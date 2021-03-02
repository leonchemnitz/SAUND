/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SAUNDAudioProcessor::SAUNDAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
    : AudioProcessor(
          BusesProperties()
#if !JucePlugin_IsMidiEffect
#if !JucePlugin_IsSynth
              .withInput("Input", juce::AudioChannelSet::stereo(), true)
#endif
              .withOutput("Output", juce::AudioChannelSet::stereo(), true)
#endif
      )
#endif
{

  addParameter(gain = new juce::AudioParameterFloat("gain", // parameterID
                                                    "Gain", // parameter name
                                                    0.0f,   // minimum value
                                                    1.0f,   // maximum value
                                                    0.5f)); // default value

  for (int i = 0; i < MAX_ORDER; ++i) {
    juce::String nameAsym = "c" + juce::String(i + 1) + "_asym";
    addParameter(c_asym[i] =
                     new juce::AudioParameterFloat(nameAsym, // parameterID
                                                   nameAsym, // parameter name
                                                   0.0f,     // minimum value
                                                   1.0f,     // maximum value
                                                   0.0f));   // default value
  }

  c1_a = 1.0;
  c2_a = 0;
  c3_a = 0;
  c4_a = 0;
  c5_a = 0;
  c6_a = 0;
  c7_a = 0;
  c8_a = 0;

  c1_b = 1;
  c2_b = 0;
  c3_b = 0;
  c4_b = 0;
  c5_b = 0;
  c6_b = 0;
  c7_b = 0;
  c8_b = 0;

  inputGain = 1;
  outputGain = 1;
}

SAUNDAudioProcessor::~SAUNDAudioProcessor() {}

//==============================================================================
const juce::String SAUNDAudioProcessor::getName() const {
  return JucePlugin_Name;
}

bool SAUNDAudioProcessor::acceptsMidi() const {
#if JucePlugin_WantsMidiInput
  return true;
#else
  return false;
#endif
}

bool SAUNDAudioProcessor::producesMidi() const {
#if JucePlugin_ProducesMidiOutput
  return true;
#else
  return false;
#endif
}

bool SAUNDAudioProcessor::isMidiEffect() const {
#if JucePlugin_IsMidiEffect
  return true;
#else
  return false;
#endif
}

double SAUNDAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int SAUNDAudioProcessor::getNumPrograms() {
  return 1; // NB: some hosts don't cope very well if you tell them there are 0
            // programs, so this should be at least 1, even if you're not really
            // implementing programs.
}

int SAUNDAudioProcessor::getCurrentProgram() { return 0; }

void SAUNDAudioProcessor::setCurrentProgram(int index) {}

const juce::String SAUNDAudioProcessor::getProgramName(int index) { return {}; }

void SAUNDAudioProcessor::changeProgramName(int index,
                                            const juce::String &newName) {}

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
                                       juce::MidiBuffer &midiMessages) {
  juce::ScopedNoDenormals noDenormals;
  auto totalNumInputChannels = getTotalNumInputChannels();
  auto totalNumOutputChannels = getTotalNumOutputChannels();

  auto bufferSize = buffer.getNumSamples();

  for (int channel = 0; channel < totalNumInputChannels; ++channel) {
    auto *channelData = buffer.getWritePointer(channel);

    for (int i = 0; i < bufferSize; ++i) {
      channelData[i] = distort(channelData[i] * inputGain) * outputGain;
    }
  }

  lufsMeter.processBlock(buffer);
}

double SAUNDAudioProcessor::distortAsym(double in) {
  in += 1;
  in /= 2;

  double out = 0;
  out += in * c1_a;

  in *= in;
  out += in * c2_a;

  in *= in;
  out += in * c3_a;

  in *= in;
  out += in * c4_a;

  in *= in;
  out += in * c5_a;

  in *= in;
  out += in * c6_a;

  in *= in;
  out += in * c7_a;

  in *= in;
  out += in * c8_a;

  double coefficientSum = c1_a + c2_a + c3_a + c4_a + c5_a + c6_a + c7_a + c8_a;

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
  out += in * c1_b;

  in *= in;
  out += in * c2_b;

  in *= in;
  out += in * c3_b;

  in *= in;
  out += in * c4_b;

  in *= in;
  out += in * c5_b;

  in *= in;
  out += in * c6_b;

  in *= in;
  out += in * c7_b;

  in *= in;
  out += in * c8_b;

  double coefficientSum = c1_b + c2_b + c3_b + c4_b + c5_b + c6_b + c7_b + c8_b;

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
  out = distortSym(out);

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

//==============================================================================
void SAUNDAudioProcessor::getStateInformation(juce::MemoryBlock &destData) {
  // You should use this method to store your parameters in the memory block.
  // You could do that either as raw data, or use the XML or ValueTree classes
  // as intermediaries to make it easy to save and load complex data.
}

void SAUNDAudioProcessor::setStateInformation(const void *data,
                                              int sizeInBytes) {
  // You should use this method to restore your parameters from this memory
  // block, whose contents will have been created by the getStateInformation()
  // call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
  return new SAUNDAudioProcessor();
}
