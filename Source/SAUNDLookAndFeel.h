#pragma once

#include <JuceHeader.h>


class SAUNDLookAndFeel : public juce::LookAndFeel_V4
{
public:
  void drawLinearSlider(Graphics &, int x, int y, int width, int height, float sliderPos, float minSliderPos, float maxSliderPos, const Slider::SliderStyle, Slider &) override;
};
