/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "CurveComponent.h"
#include "WaveformComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public juce::Component,
                       private juce::Timer,
                       public juce::Slider::Listener
{
public:
    //==============================================================================
    MainComponent (SAUNDAudioProcessor& p);
    ~MainComponent() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void timerCallback() override;
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SAUNDAudioProcessor& p;


    std::unique_ptr<CurveComponent> curveComponent;
    std::unique_ptr<WaveformComponent> waveformComponent;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> outputGain;
    std::unique_ptr<juce::Slider> c1_a;
    std::unique_ptr<juce::Slider> c2_a;
    std::unique_ptr<juce::Slider> c3_a;
    std::unique_ptr<juce::Slider> c4_a;
    std::unique_ptr<juce::Slider> c5_a;
    std::unique_ptr<juce::Slider> c6_a;
    std::unique_ptr<juce::Slider> c7_a;
    std::unique_ptr<juce::Slider> c8_a;
    std::unique_ptr<juce::Slider> inputGain;
    std::unique_ptr<juce::Slider> c1_b;
    std::unique_ptr<juce::Slider> c2_b;
    std::unique_ptr<juce::Slider> c3_b;
    std::unique_ptr<juce::Slider> c4_b;
    std::unique_ptr<juce::Slider> c5_b;
    std::unique_ptr<juce::Slider> c6_b;
    std::unique_ptr<juce::Slider> c7_b;
    std::unique_ptr<juce::Slider> c8_b;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

