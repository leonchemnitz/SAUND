
#include "PluginProcessor.h"
#include "PluginEditor.h"

juce::AudioProcessorValueTreeState::ParameterLayout createParameterLayout() {
  juce::AudioProcessorValueTreeState::ParameterLayout params;

  params.add(
      std::make_unique<juce::AudioParameterFloat>("gain", // parameterID
                                                  "gain", // parameter name
                                                  0.0f,   // minimum value
                                                  1.0f,   // maximum value
                                                  0.5f)   // default value
  );

  for (int i = 0; i < MAX_ORDER; ++i) {
    juce::String nameAsym = "c" + juce::String(i + 1) + "_asym";
    params.add(std::make_unique<AudioParameterFloat>(nameAsym, nameAsym, 0.0f,
                                                     1.0f, 0.0f));

    juce::String nameSym = "c" + juce::String(i + 1) + "_sym";
    params.add(std::make_unique<AudioParameterFloat>(nameSym, nameSym, 0.0f,
                                                     1.0f, 0.0f));
  }

  return params;
}

SAUNDAudioProcessor::SAUNDAudioProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo(), true)
              .withOutput("Output", juce::AudioChannelSet::stereo(), true)),
      parameters(*this, &(this->undoManager), juce::Identifier("SAUND"),
                 createParameterLayout()) {

  gainParameter = parameters.getRawParameterValue("gain");

  for (int i = 0; i < MAX_ORDER; ++i) {
    c_asym[i] =
        parameters.getRawParameterValue("c" + juce::String(i + 1) + "_asym");

    c_sym[i] =
        parameters.getRawParameterValue("c" + juce::String(i + 1) + "_sym");
  }
}

SAUNDAudioProcessor::~SAUNDAudioProcessor() {}

const juce::String SAUNDAudioProcessor::getName() const {
  return JucePlugin_Name;
}

bool SAUNDAudioProcessor::acceptsMidi() const { return false; }

bool SAUNDAudioProcessor::producesMidi() const { return false; }

bool SAUNDAudioProcessor::isMidiEffect() const { return false; }

double SAUNDAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int SAUNDAudioProcessor::getNumPrograms() {
  return 1; // NB: some hosts don't cope very well if you tell them there are 0
            // programs, so this should be at least 1, even if you're not really
            // implementing programs.
}

int SAUNDAudioProcessor::getCurrentProgram() { return 0; }

void SAUNDAudioProcessor::setCurrentProgram(int /*index*/) {}

const juce::String SAUNDAudioProcessor::getProgramName(int /*index*/) {
  return {};
}

void SAUNDAudioProcessor::changeProgramName(int /*index*/,
                                            const juce::String & /*newName*/) {}

//==============================================================================
void SAUNDAudioProcessor::prepareToPlay(double sampleRate,
                                        int samplesPerBlock) {
  lufsMeter.prepareToPlay(sampleRate, getNumInputChannels(), samplesPerBlock,
                          5);
}

void SAUNDAudioProcessor::releaseResources() {
  // When playback stops, you can use this as an opportunity to free up any
  // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SAUNDAudioProcessor::isBusesLayoutSupported(
    const BusesLayout &layouts) const {
#if JucePlugin_IsMidiEffect
  juce::ignoreUnused(layouts);
  return true;
#else
  // This is the place where you check if the layout is supported.
  // In this template code we only support mono or stereo.
  // Some plugin hosts, such as certain GarageBand versions, will only
  // load plugins that support stereo bus layouts.
  if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono() &&
      layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
    return false;

    // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
  if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
    return false;
#endif

  return true;
#endif
}
#endif

void SAUNDAudioProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                       juce::MidiBuffer & /*midiMessages*/) {
  juce::ScopedNoDenormals noDenormals;
  auto totalNumInputChannels = getTotalNumInputChannels();
  // auto totalNumOutputChannels = getTotalNumOutputChannels();

  auto bufferSize = buffer.getNumSamples();

  for (int channel = 0; channel < totalNumInputChannels; ++channel) {
    auto *channelData = buffer.getWritePointer(channel);

    for (int i = 0; i < bufferSize; ++i) {
      channelData[i] = distort(channelData[i]) * (*gainParameter);
    }
  }

  lufsMeter.processBlock(buffer);
}

double SAUNDAudioProcessor::distortAsym(double in) {
  in += 1;
  in /= 2;

  double out = 0;
  double coefficientSum = 0;

  for (int i = 0; i < MAX_ORDER; ++i) {
    out += in * *c_asym[i];
    in *= in;

    coefficientSum += *c_asym[i];
  }

  if (coefficientSum != 0) {
    out /= coefficientSum;
  }

  out *= 2;
  out -= 1;

  return out;
}
double SAUNDAudioProcessor::distortSym(double in) {
  bool isPositive = false;
  if (in >= 0) {
    isPositive = true;
    in *= -1;
  }

  in += 1;

  double out = 0;
  double coefficientSum = 0.0;

  for (int i = 0; i < MAX_ORDER; ++i) {
    out += in * *c_sym[i];
    in *= in;

    coefficientSum += *c_sym[i];
  }

  if (coefficientSum != 0) {
    out /= coefficientSum;
  }

  out -= 1;

  if (isPositive) {
    out *= -1;
  }

  return out;
}

double SAUNDAudioProcessor::distort(double in) {
  double out = distortAsym(in);
  // out = distortSym(out);

  if (out > 1)
    out = 1;

  if (out < -1)
    out = -1;

  return out;
}

//==============================================================================
bool SAUNDAudioProcessor::hasEditor() const { return true; }

juce::AudioProcessorEditor *SAUNDAudioProcessor::createEditor() {
  return new SAUNDAudioProcessorEditor(*this);
}

void SAUNDAudioProcessor::getStateInformation(juce::MemoryBlock &destData) {
  auto state = parameters.copyState();
  std::unique_ptr<juce::XmlElement> xml(state.createXml());
  copyXmlToBinary(*xml, destData);
}

void SAUNDAudioProcessor::setStateInformation(const void *data,
                                              int sizeInBytes) {
  std::unique_ptr<juce::XmlElement> xmlState(
      getXmlFromBinary(data, sizeInBytes));

  if (xmlState.get() != nullptr)
    if (xmlState->hasTagName(parameters.state.getType()))
      parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
  return new SAUNDAudioProcessor();
}
