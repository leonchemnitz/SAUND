/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "MainComponent.h"
#include "PluginProcessor.h"
#include <JuceHeader.h>


//==============================================================================
/**
 */
class SAUNDAudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  SAUNDAudioProcessorEditor(SAUNDAudioProcessor &);
  ~SAUNDAudioProcessorEditor() override;

  //==============================================================================
  void paint(juce::Graphics &) override;
  void resized() override;
  void isClipping(bool);

private:
  MainComponent mainComponent;

  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  SAUNDAudioProcessor &audioProcessor;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SAUNDAudioProcessorEditor)
};
