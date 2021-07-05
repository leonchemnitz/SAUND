#include "SAUNDLookAndFeel.h"

void SAUNDLookAndFeel::drawLinearSlider(Graphics &g, int x, int y, int width,
                                        int height, float sliderPos,
                                        float minSliderPos, float maxSliderPos,
                                        const Slider::SliderStyle style,
                                        Slider &) {
  g.setColour(juce::Colours::black);

  float trackThickness = 2;
  float grabberThickness = 4;

  if (style == Slider::SliderStyle::LinearVertical) {
    g.drawLine(juce::Line<float>(x + width / 2.0, y, width / 2.0, y + height),
               trackThickness);

    float grabberYPos = y + height * sliderPos;
    g.drawLine(juce::Line<float>(x, sliderPos, x + width, sliderPos),
               grabberThickness);
  }
}