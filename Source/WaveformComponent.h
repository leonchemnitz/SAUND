/*
  ==============================================================================

    WaveformComponent.h
    Created: 27 Feb 2021 7:21:11pm
    Author:  Leon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class WaveformComponent  : public juce::Component
{
public:
    WaveformComponent(SAUNDAudioProcessor& p);
    ~WaveformComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SAUNDAudioProcessor& p;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveformComponent)
};
