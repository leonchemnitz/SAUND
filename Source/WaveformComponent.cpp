/*
  ==============================================================================

    WaveformComponent.cpp
    Created: 27 Feb 2021 7:21:11pm
    Author:  Leon

  ==============================================================================
*/

#include <JuceHeader.h>
#include "WaveformComponent.h"
#include <math.h>

//==============================================================================
WaveformComponent::WaveformComponent(SAUNDAudioProcessor& p) : p(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

WaveformComponent::~WaveformComponent()
{
}

void WaveformComponent::paint (juce::Graphics& g)
{

    g.fillAll(juce::Colours::white);   // clear the background
    g.setColour(juce::Colours::black);
    g.drawRect(getLocalBounds(), 1);   // draw an outline around the component



    const int STEP_SIZE = 2;
    const int width = getLocalBounds().getWidth();
    const int height = getLocalBounds().getHeight();

    int xPosOld = 0;
    int yPosOld = 0;

    g.setColour(juce::Colours::black);

    juce::Path path;
    path.startNewSubPath(0, height);

    for (int xPos = 0; xPos < width; xPos += STEP_SIZE) {
        double inValue = sin((double)xPos / (double)width * 3.1415 * 2);
        double outValue = p.distort(inValue);

        int yPos = height - ((outValue + 1) / 2) * height;

        path.lineTo(xPos, yPos);
    }


    path.lineTo(width, 0);

    g.strokePath(path, juce::PathStrokeType(2.0f));

    g.drawLine(0, height / 2, width, height / 2, 1);

}

void WaveformComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
