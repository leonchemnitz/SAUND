#pragma once

#include "MainComponent.h"
#include "PluginProcessor.h"
#include <JuceHeader.h>

class SAUNDAudioProcessorEditor : public juce::AudioProcessorEditor,
                                  public juce::ApplicationCommandTarget {
public:
  SAUNDAudioProcessorEditor(SAUNDAudioProcessor &);
  ~SAUNDAudioProcessorEditor() override;

  enum Commands { UNDO, REDO };

  void paint(juce::Graphics &) override;
  void resized() override;
  void isClipping(bool);

  ApplicationCommandTarget *getNextCommandTarget() override;
  void getAllCommands(juce::Array<CommandID> &commands) override;
  void getCommandInfo(CommandID commandID,
                      ApplicationCommandInfo &result) override;
  bool perform(const InvocationInfo &info) override;

private:
  SAUNDAudioProcessor &audioProcessor;

  MainComponent mainComponent;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SAUNDAudioProcessorEditor)
};
