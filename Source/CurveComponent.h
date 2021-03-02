/*
  ==============================================================================

    CurveComponent.h
    Created: 22 Feb 2021 11:54:05am
    Author:  Leon

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/*
*/
class CurveComponent  : public juce::Component
{
public:
    CurveComponent(SAUNDAudioProcessor& p);
    ~CurveComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    SAUNDAudioProcessor& p;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CurveComponent)
};
