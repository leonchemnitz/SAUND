#include "MainComponent.h"

#define BORDER_LEFT 20
#define PARAMETER_WIDTH 100

MainComponent::MainComponent(SAUNDAudioProcessor &p)
    : p(p), valueTreeState(p.parameters) {

  setLookAndFeel(&lookAndFeel);

  gainLabel.setText("Gain", juce::dontSendNotification);
  addAndMakeVisible(gainLabel);

  addAndMakeVisible(gainSlider);
  gainAttachment.reset(
      new SliderAttachment(valueTreeState, "gain", gainSlider));
  gainSlider.setBounds(720, 220, 88, 200);
  gainSlider.setSliderStyle(juce::Slider::LinearVertical);
  gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  gainSlider.setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);

  for (int i = 0; i < MAX_ORDER; ++i) {
    juce::String nameAsym = "c" + juce::String(i + 1) + "_asym";

    addAndMakeVisible(cAsymSlider[i]);
    cAsymAttachment[i].reset(
        new SliderAttachment(valueTreeState, nameAsym, cAsymSlider[i]));
    cAsymSlider[i].setBounds(BORDER_LEFT + i * PARAMETER_WIDTH, 15, 88, 80);
    cAsymSlider[i].setSliderStyle(juce::Slider::LinearVertical);
    cAsymSlider[i].setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    cAsymSlider[i].setColour(juce::Slider::textBoxTextColourId,
                             juce::Colours::black);

    juce::String nameSym = "c" + juce::String(i + 1) + "_sym";

    addAndMakeVisible(cSymSlider[i]);
    cSymAttachment[i].reset(
        new SliderAttachment(valueTreeState, nameSym, cSymSlider[i]));
    cSymSlider[i].setBounds(BORDER_LEFT + i * PARAMETER_WIDTH, 115, 88, 80);
    cSymSlider[i].setSliderStyle(juce::Slider::LinearVertical);
    cSymSlider[i].setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    cSymSlider[i].setColour(juce::Slider::textBoxTextColourId,
                            juce::Colours::black);
  }

  curveComponent.reset(new CurveComponent(p));
  addAndMakeVisible(curveComponent.get());
  curveComponent->setBounds(BORDER_LEFT, 220, 200, 200);

  waveformComponent.reset(new WaveformComponent(p));
  addAndMakeVisible(waveformComponent.get());
  waveformComponent->setBounds(BORDER_LEFT + 240, 220, 200, 200);

  setSize(825, 440);

  startTimerHz(5);
}

MainComponent::~MainComponent() { setLookAndFeel(nullptr); }

//==============================================================================
void MainComponent::paint(juce::Graphics &g) {
  g.fillAll(juce::Colours::white);

  {
    int width = 32, height = 14;
    int x = curveComponent->getBounds().getCentreX() - width / 2;
    int y = curveComponent->getBottom();
    juce::String text(TRANS("x"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int width = 32, height = 14;
    int x = curveComponent->getBounds().getX() - width / 2;
    int y = curveComponent->getBottom();
    juce::String text(TRANS("-1"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }
  {
    int width = 32, height = 14;
    int x = curveComponent->getBounds().getRight() - width / 2;
    int y = curveComponent->getBottom();
    juce::String text(TRANS("1"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int width = 32, height = 14;
    int x = curveComponent->getX() - 23;
    int y = curveComponent->getBottom() - height;
    juce::String text(TRANS("-1"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }
  {
    int width = 32, height = 14;
    int x = curveComponent->getX() - 23;
    int y = curveComponent->getY();

    juce::String text(TRANS("1"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int width = 32, height = 14;
    int x = curveComponent->getX() - height - 2;
    int y = curveComponent->getBounds().getCentreY() + width / 2;
    juce::String text(TRANS("H(x)"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.saveState();
    g.addTransform(juce::AffineTransform::rotation(-3.1415 / 2, x, y));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
    g.restoreState();
  }

  {
    int width = 32, height = 14;
    int x = waveformComponent->getBounds().getCentreX() - width / 2;
    int y = waveformComponent->getBottom();
    juce::String text(TRANS("x"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int width = 32, height = 14;
    int x = waveformComponent->getBounds().getX() - width / 2;
    int y = waveformComponent->getBottom();
    juce::String text(TRANS("0"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }
  {
    int width = 32, height = 14;
    int x = waveformComponent->getBounds().getRight() - width / 2;
    int y = waveformComponent->getBottom();
    juce::String text(TRANS("3.14"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int width = 32, height = 14;
    int x = waveformComponent->getX() - 23;
    int y = waveformComponent->getBottom() - height;
    juce::String text(TRANS("-1"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }
  {
    int width = 32, height = 14;
    int x = waveformComponent->getX() - 23;
    int y = waveformComponent->getY();

    juce::String text(TRANS("1"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(10.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  {
    int width = 70, height = 14;
    int x = waveformComponent->getX() - height - 4;
    int y = waveformComponent->getBounds().getCentreY() + width / 2;
    juce::String text(TRANS("H(sin(x))"));
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.saveState();
    g.addTransform(juce::AffineTransform::rotation(-3.1415 / 2, x, y));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
    g.restoreState();
  }

  {
    int x = 720, y = 205, width = 88, height = 30;
    juce::String text(TRANS("Gain"));
    juce::Colour fillColour = juce::Colours::black;
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  for (int i = 0; i < MAX_ORDER; i++) {
    int width = 32;
    int height = 30;
    int x = BORDER_LEFT + i * PARAMETER_WIDTH + 28;
    int y = 100;
    int xPower = x + 6;
    int yPower = y - 5;

    juce::String text(juce::CharPointer_UTF8("x"));
    juce::String power(i + 1);
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);

    g.setFont(
        juce::Font(9.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(power, xPower, yPower, width, height,
               juce::Justification::centred, true);
  }

  for (int i = 0; i < MAX_ORDER; i++) {
    int width = 32;
    int height = 30;
    int x = BORDER_LEFT + i * PARAMETER_WIDTH + 28;
    int y = 0;
    int xPower = x + 6;
    int yPower = y - 5;

    juce::String text(juce::CharPointer_UTF8("x"));
    juce::String power(i + 1);
    juce::Colour fillColour = juce::Colours::black;

    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);

    g.setFont(
        juce::Font(9.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(power, xPower, yPower, width, height,
               juce::Justification::centred, true);
  }

  {
    int x = 683, y = 233, width = 12, height = 12;
    juce::Colour fillColour = juce::Colours::white;
    juce::Colour strokeColour = juce::Colours::black;
    g.setColour(fillColour);
    g.fillRect(x, y, width, height);
    g.setColour(strokeColour);
    g.drawRect(x, y, width, height, 2);
  }

  {
    int x = 620, y = 225, width = 52, height = 26;
    juce::String text(TRANS("clipping"));
    juce::Colour fillColour = juce::Colours::black;
    g.setColour(fillColour);
    g.setFont(
        juce::Font(15.00f, juce::Font::plain).withTypefaceStyle("Regular"));
    g.drawText(text, x, y, width, height, juce::Justification::centred, true);
  }

  // g.drawText("LUFS", 600, 300, 50, 20, juce::Justification::centred, true);
  // juce::String value(p.lufsMeter.getMomentaryLoudness(), 2, false);
  // g.drawText(value, 600, 330, 50, 20, juce::Justification::centred, true);
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