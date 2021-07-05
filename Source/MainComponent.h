#pragma once

#include "CurveComponent.h"
#include "PluginProcessor.h"
#include "WaveformComponent.h"
#include <JuceHeader.h>
#include "SAUNDLookAndFeel.h"

class MainComponent : public juce::Component,
                      private juce::Timer,
                      public juce::AudioProcessorValueTreeState::Listener {
public:
  MainComponent(SAUNDAudioProcessor &p);
  ~MainComponent() override;

  void timerCallback() override;

  void paint(juce::Graphics &g) override;
  void resized() override;
  void parameterChanged(const String &parameterID, float newValue) override;

private:
  SAUNDAudioProcessor &p;
  juce::AudioProcessorValueTreeState &valueTreeState;

  SAUNDLookAndFeel lookAndFeel;

  std::unique_ptr<CurveComponent> curveComponent;
  std::unique_ptr<WaveformComponent> waveformComponent;

  typedef juce::AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
  typedef juce::AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;

  juce::Label gainLabel;
  juce::Slider gainSlider;
  std::unique_ptr<SliderAttachment> gainAttachment;

  juce::Slider cAsymSlider[MAX_ORDER];
  std::unique_ptr<SliderAttachment> cAsymAttachment[MAX_ORDER];

  juce::Slider cSymSlider[MAX_ORDER];
  std::unique_ptr<SliderAttachment> cSymAttachment[MAX_ORDER];

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MainComponent)
};