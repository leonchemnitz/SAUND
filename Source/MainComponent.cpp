#include "MainComponent.h"

#define BORDER_LEFT 20
#define PARAMETER_WIDTH 100

MainComponent::MainComponent(SAUNDAudioProcessor &p)
    : p(p), valueTreeState(p.parameters) {

  gainLabel.setText("Gain", juce::dontSendNotification);
  addAndMakeVisible(gainLabel);

  addAndMakeVisible(gainSlider);
  gainAttachment.reset(
      new SliderAttachment(valueTreeState, "gain", gainSlider));
  gainSlider.setBounds(884, 48, 88, 80);
  gainSlider.setSliderStyle(juce::Slider::Rotary);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  gainSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);

  for (int i = 0; i < MAX_ORDER; ++i) {
    juce::String nameAsym = "c" + juce::String(i + 1) + "_asym";

    addAndMakeVisible(cAsymSlider[i]);
    cAsymAttachment[i].reset(
        new SliderAttachment(valueTreeState, nameAsym, cAsymSlider[i]));
    cAsymSlider[i].setBounds(BORDER_LEFT + i * PARAMETER_WIDTH, 50, 88, 80);
    cAsymSlider[i].setSliderStyle(juce::Slider::LinearVertical);
    cAsymSlider[i].setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    cAsymSlider[i].setColour(juce::Slider::textBoxTextColourId,
                             juce::Colours::black);

    juce::String nameSym = "c" + juce::String(i + 1) + "_sym";

    addAndMakeVisible(cSymSlider[i]);
    cSymAttachment[i].reset(
        new SliderAttachment(valueTreeState, nameSym, cSymSlider[i]));
    cSymSlider[i].setBounds(BORDER_LEFT + i * PARAMETER_WIDTH, 160, 88, 80);
    cSymSlider[i].setSliderStyle(juce::Slider::LinearVertical);
    cSymSlider[i].setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    cSymSlider[i].setColour(juce::Slider::textBoxTextColourId,
                            juce::Colours::black);
  }

  curveComponent.reset(new CurveComponent(p));
  addAndMakeVisible(curveComponent.get());
  curveComponent->setBounds(500, 380, 200, 200);

  waveformComponent.reset(new WaveformComponent(p));
  addAndMakeVisible(waveformComponent.get());
  waveformComponent->setBounds(750, 380, 200, 200);

  setSize(1000, 600);

  startTimerHz(5);
}

MainComponent::~MainComponent() {}

//==============================================================================
void MainComponent::paint(juce::Graphics &g) {
  g.fillAll(juce::Colours::white);

  {
    int x = 876, y = 16, width = 104, height = 30;
    juce::String text(TRANS("output gaaainz"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 40, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xc2\xb9"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 0, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 120, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xc2\xb2"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 80, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 200, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xc2\xb3"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 160, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 280, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb4"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 240, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 356, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb5"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 316, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 436, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb6"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 396, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 516, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb7"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 476, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 596, y = 0, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb8"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 556, y = 120, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 776, y = 16, width = 104, height = 30;
    juce::String text(TRANS("input gain"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 952, y = 152, width = 12, height = 12;
    juce::Colour fillColour = juce::Colours::white;
    juce::Colour strokeColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.fillRect(x, y, width, height);
    g.setColour(strokeColour);
    g.drawRect(x, y, width, height, 2);
  }

  {
    int x = 896, y = 144, width = 52, height = 26;
    juce::String text(TRANS("clipping"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 40, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xc2\xb9"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 0, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 120, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xc2\xb2"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 80, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 200, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xc2\xb3"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 160, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 280, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb4"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 240, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 356, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb5"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 316, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 436, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb6"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 396, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 516, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb7"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 476, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 596, y = 140, width = 32, height = 30;
    juce::String text(juce::CharPointer_UTF8("x\xe2\x81\xb8"));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int x = 556, y = 260, width = 32, height = 36;
    juce::String text(TRANS("c = "));
    juce::Colour fillColour = juce::Colours::black;
    //[UserPaintCustomArguments] Customize the painting arguments here..
    //[/UserPaintCustomArguments]
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  //[UserPaint] Add your own custom painting code here..

  g.drawText("LUFS", 200, 300, 50, 20, juce::Justification::centred, true);
  juce::String value(p.lufsMeter.getMomentaryLoudness(), 2, false);
  g.drawText(value, 200, 330, 50, 20, juce::Justification::centred, true);
  //[/UserPaint]
}

void MainComponent::resized() {}

void MainComponent::parameterChanged(const String & /*parameterID*/,
                                     float /*newValue*/) {

  curveComponent->repaint();
  waveformComponent->repaint();
}

void MainComponent::timerCallback() {
  // TODO: mach das nicht...
  repaint();
}