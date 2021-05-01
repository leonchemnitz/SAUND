/*
  ==============================================================================

    CurveComponent.cpp
    Created: 22 Feb 2021 11:54:05am
    Author:  Leon

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CurveComponent.h"

//==============================================================================
CurveComponent::CurveComponent(SAUNDAudioProcessor& p): p(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

}

CurveComponent::~CurveComponent()
{
}

void CurveComponent::paint (juce::Graphics& g)
{

    g.fillAll (juce::Colours::white);   // clear the background
    g.setColour (juce::Colours::black);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component



    const int STEP_SIZE = 2;
    const int width = getLocalBounds().getWidth(); 
    const int height = getLocalBounds().getHeight();

    int xPosOld = 0;
    int yPosOld = 0;

    g.setColour(juce::Colours::black);

    juce::Path path;
    path.startNewSubPath(0, height);

    for (int xPos = 0; xPos < width; xPos += STEP_SIZE) {
        double inValue = ((double)xPos / (double)width) * 2 - 1;
        double outValue = p.distort(inValue);
        
        float yPos = height - ((outValue + 1) / 2) * height;

        path.lineTo(xPos, yPos);
    }


    path.lineTo(width, 0);
    //path.closeSubPath();

    g.strokePath(path, juce::PathStrokeType(2.0f));

    g.drawLine(0, height/2, width, height/2, 1);
    g.drawLine(width/2, 0, width/ 2, height, 1);


    g.strokePath(path, juce::PathStrokeType(2.0f));

    float dashPattern[2] ={2,2};

    g.drawDashedLine(juce::Line<float>(0, height/4, width, height/4), dashPattern, 2,1);
    g.drawDashedLine(juce::Line<float>(0, 3*height/4, width, 3*height/4), dashPattern, 2,1);

    g.drawDashedLine(juce::Line<float>(width/4, 0, width/ 4, height), dashPattern, 2,1);
    g.drawDashedLine(juce::Line<float>(3*width/4, 0, 3*width/ 4, height), dashPattern, 2,1);

}

void CurveComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
