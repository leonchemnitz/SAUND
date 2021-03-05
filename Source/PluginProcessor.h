#pragma once

#include "Ebu128LoudnessMeter.h"
#include <JuceHeader.h>

class SAUNDAudioProcessor : public juce::AudioProcessor {
public:
  SAUNDAudioProcessor();
  ~SAUNDAudioProcessor() override;

  void prepareToPlay(double sampleRate, int samplesPerBlock) override;
  void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations
  bool isBusesLayoutSupported(const BusesLayout &layouts) const override;
#endif

  void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;

  juce::AudioProcessorEditor *createEditor() override;
  bool hasEditor() const override;

  const juce::String getName() const override;

  bool acceptsMidi() const override;
  bool producesMidi() const override;
  bool isMidiEffect() const override;
  double getTailLengthSeconds() const override;

  int getNumPrograms() override;
  int getCurrentProgram() override;
  void setCurrentProgram(int index) override;
  const juce::String getProgramName(int index) override;
  void changeProgramName(int index, const juce::String &newName) override;

  void getStateInformation(juce::MemoryBlock &destData) override;
  void setStateInformation(const void *data, int sizeInBytes) override;

  double distort(double in);

#define MAX_ORDER 8

  juce::UndoManager undoManager;
  juce::AudioProcessorValueTreeState parameters;

  std::atomic<float> *gainParameter = nullptr;

  std::atomic<float> *c_asym[MAX_ORDER];
  std::atomic<float> *c_sym[MAX_ORDER];

  Ebu128LoudnessMeter lufsMeter;

private:
  double distortAsym(double in);
  double distortSym(double in);

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SAUNDAudioProcessor)
};
