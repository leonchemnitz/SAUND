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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"

//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent(SAUNDAudioProcessor &p) : p(p) {
  //[Constructor_pre] You can add your own custom stuff here..
  //[/Constructor_pre]

  outputGain.reset(new juce::Slider("outputGain"));
  addAndMakeVisible(outputGain.get());
  outputGain->setRange(0, 1, 0.001);
  outputGain->setSliderStyle(juce::Slider::Rotary);
  outputGain->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  outputGain->setColour(juce::Slider::textBoxTextColourId,
                        juce::Colours::black);
  outputGain->addListener(this);

  outputGain->setBounds(884, 48, 88, 80);

  c1_a.reset(new juce::Slider("c1_a"));
  addAndMakeVisible(c1_a.get());
  c1_a->setRange(0, 1, 0.001);
  c1_a->setSliderStyle(juce::Slider::LinearVertical);
  c1_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c1_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c1_a->addListener(this);

  c1_a->setBounds(32, 20, 46, 128);

  c2_a.reset(new juce::Slider("c2_a"));
  addAndMakeVisible(c2_a.get());
  c2_a->setRange(0, 1, 0.001);
  c2_a->setSliderStyle(juce::Slider::LinearVertical);
  c2_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c2_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c2_a->addListener(this);

  c2_a->setBounds(112, 20, 46, 128);

  c3_a.reset(new juce::Slider("c3_a"));
  addAndMakeVisible(c3_a.get());
  c3_a->setRange(0, 1, 0.001);
  c3_a->setSliderStyle(juce::Slider::LinearVertical);
  c3_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c3_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c3_a->addListener(this);

  c3_a->setBounds(191, 20, 46, 128);

  c4_a.reset(new juce::Slider("c4_a"));
  addAndMakeVisible(c4_a.get());
  c4_a->setRange(0, 1, 0.001);
  c4_a->setSliderStyle(juce::Slider::LinearVertical);
  c4_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c4_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c4_a->addListener(this);

  c4_a->setBounds(271, 20, 46, 128);

  c5_a.reset(new juce::Slider("c5_a"));
  addAndMakeVisible(c5_a.get());
  c5_a->setRange(0, 1, 0.001);
  c5_a->setSliderStyle(juce::Slider::LinearVertical);
  c5_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c5_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c5_a->addListener(this);

  c5_a->setBounds(349, 19, 46, 128);

  c6_a.reset(new juce::Slider("c6_a"));
  addAndMakeVisible(c6_a.get());
  c6_a->setRange(0, 1, 0.001);
  c6_a->setSliderStyle(juce::Slider::LinearVertical);
  c6_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c6_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c6_a->addListener(this);

  c6_a->setBounds(429, 19, 46, 128);

  c7_a.reset(new juce::Slider("c7_a"));
  addAndMakeVisible(c7_a.get());
  c7_a->setRange(0, 1, 0.001);
  c7_a->setSliderStyle(juce::Slider::LinearVertical);
  c7_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c7_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c7_a->addListener(this);

  c7_a->setBounds(508, 19, 46, 128);

  c8_a.reset(new juce::Slider("c8_a"));
  addAndMakeVisible(c8_a.get());
  c8_a->setRange(0, 1, 0.001);
  c8_a->setSliderStyle(juce::Slider::LinearVertical);
  c8_a->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c8_a->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c8_a->addListener(this);

  c8_a->setBounds(588, 19, 46, 128);

  inputGain.reset(new juce::Slider("inputGain"));
  addAndMakeVisible(inputGain.get());
  inputGain->setRange(0, 8, 0.001);
  inputGain->setSliderStyle(juce::Slider::Rotary);
  inputGain->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  inputGain->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  inputGain->addListener(this);

  inputGain->setBounds(784, 48, 88, 80);

  c1_b.reset(new juce::Slider("c1_b"));
  addAndMakeVisible(c1_b.get());
  c1_b->setRange(0, 1, 0.001);
  c1_b->setSliderStyle(juce::Slider::LinearVertical);
  c1_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c1_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c1_b->addListener(this);

  c1_b->setBounds(31, 161, 46, 128);

  c2_b.reset(new juce::Slider("c2_b"));
  addAndMakeVisible(c2_b.get());
  c2_b->setRange(0, 1, 0.001);
  c2_b->setSliderStyle(juce::Slider::LinearVertical);
  c2_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c2_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c2_b->addListener(this);

  c2_b->setBounds(111, 161, 46, 128);

  c3_b.reset(new juce::Slider("c3_b"));
  addAndMakeVisible(c3_b.get());
  c3_b->setRange(0, 1, 0.001);
  c3_b->setSliderStyle(juce::Slider::LinearVertical);
  c3_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c3_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c3_b->addListener(this);

  c3_b->setBounds(190, 161, 46, 128);

  c4_b.reset(new juce::Slider("c4_b"));
  addAndMakeVisible(c4_b.get());
  c4_b->setRange(0, 1, 0.001);
  c4_b->setSliderStyle(juce::Slider::LinearVertical);
  c4_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c4_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c4_b->addListener(this);

  c4_b->setBounds(270, 161, 46, 128);

  c5_b.reset(new juce::Slider("c5_b"));
  addAndMakeVisible(c5_b.get());
  c5_b->setRange(0, 1, 0.001);
  c5_b->setSliderStyle(juce::Slider::LinearVertical);
  c5_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c5_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c5_b->addListener(this);

  c5_b->setBounds(348, 160, 46, 128);

  c6_b.reset(new juce::Slider("c6_b"));
  addAndMakeVisible(c6_b.get());
  c6_b->setRange(0, 1, 0.001);
  c6_b->setSliderStyle(juce::Slider::LinearVertical);
  c6_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c6_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c6_b->addListener(this);

  c6_b->setBounds(428, 160, 46, 128);

  c7_b.reset(new juce::Slider("c7_b"));
  addAndMakeVisible(c7_b.get());
  c7_b->setRange(0, 1, 0.001);
  c7_b->setSliderStyle(juce::Slider::LinearVertical);
  c7_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c7_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c7_b->addListener(this);

  c7_b->setBounds(507, 160, 46, 128);

  c8_b.reset(new juce::Slider("c8_b"));
  addAndMakeVisible(c8_b.get());
  c8_b->setRange(0, 1, 0.001);
  c8_b->setSliderStyle(juce::Slider::LinearVertical);
  c8_b->setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
  c8_b->setColour(juce::Slider::textBoxTextColourId, juce::Colours::black);
  c8_b->addListener(this);

  c8_b->setBounds(587, 160, 46, 128);

  //[UserPreSize]
  curveComponent.reset(new CurveComponent(p));
  addAndMakeVisible(curveComponent.get());
  curveComponent->setBounds(500, 380, 200, 200);

  waveformComponent.reset(new WaveformComponent(p));
  addAndMakeVisible(waveformComponent.get());
  waveformComponent->setBounds(750, 380, 200, 200);

  c1_a->setValue(p.c1_a);
  c2_a->setValue(p.c2_a);
  c3_a->setValue(p.c3_a);
  c4_a->setValue(p.c4_a);
  c5_a->setValue(p.c5_a);
  c6_a->setValue(p.c6_a);
  c7_a->setValue(p.c7_a);
  c8_a->setValue(p.c8_a);

  c1_b->setValue(p.c1_b);
  c2_b->setValue(p.c2_b);
  c3_b->setValue(p.c3_b);
  c4_b->setValue(p.c4_b);
  c5_b->setValue(p.c5_b);
  c6_b->setValue(p.c6_b);
  c7_b->setValue(p.c7_b);
  c8_b->setValue(p.c8_b);

  inputGain->setValue(p.inputGain);
  outputGain->setValue(p.outputGain);
  //[/UserPreSize]

  setSize(1000, 600);

  //[Constructor] You can add your own custom stuff here..
  startTimerHz(5);
  //[/Constructor]
}

MainComponent::~MainComponent() {
  //[Destructor_pre]. You can add your own custom destruction code here..
  //[/Destructor_pre]

  outputGain = nullptr;
  c1_a = nullptr;
  c2_a = nullptr;
  c3_a = nullptr;
  c4_a = nullptr;
  c5_a = nullptr;
  c6_a = nullptr;
  c7_a = nullptr;
  c8_a = nullptr;
  inputGain = nullptr;
  c1_b = nullptr;
  c2_b = nullptr;
  c3_b = nullptr;
  c4_b = nullptr;
  c5_b = nullptr;
  c6_b = nullptr;
  c7_b = nullptr;
  c8_b = nullptr;

  //[Destructor]. You can add your own custom destruction code here..
  //[/Destructor]
}

//==============================================================================
void MainComponent::paint(juce::Graphics &g) {
  //[UserPrePaint] Add your own custom painting code here..
  //[/UserPrePaint]

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

void MainComponent::resized() {
  //[UserPreResize] Add your own custom resize code here..
  //[/UserPreResize]

  //[UserResized] Add your own custom resize handling here..
  //[/UserResized]
}

void MainComponent::sliderValueChanged(juce::Slider *sliderThatWasMoved) {
  //[UsersliderValueChanged_Pre]
  //[/UsersliderValueChanged_Pre]

  if (sliderThatWasMoved == outputGain.get()) {
    //[UserSliderCode_outputGain] -- add your slider handling code here..
    p.outputGain = sliderThatWasMoved->getValue();
    //[/UserSliderCode_outputGain]
  } else if (sliderThatWasMoved == c1_a.get()) {
    //[UserSliderCode_c1_a] -- add your slider handling code here..
    p.c1_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c1_a]
  } else if (sliderThatWasMoved == c2_a.get()) {
    //[UserSliderCode_c2_a] -- add your slider handling code here..
    p.c2_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c2_a]
  } else if (sliderThatWasMoved == c3_a.get()) {
    //[UserSliderCode_c3_a] -- add your slider handling code here..
    p.c3_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c3_a]
  } else if (sliderThatWasMoved == c4_a.get()) {
    //[UserSliderCode_c4_a] -- add your slider handling code here..
    p.c4_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c4_a]
  } else if (sliderThatWasMoved == c5_a.get()) {
    //[UserSliderCode_c5_a] -- add your slider handling code here..
    p.c5_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c5_a]
  } else if (sliderThatWasMoved == c6_a.get()) {
    //[UserSliderCode_c6_a] -- add your slider handling code here..
    p.c6_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c6_a]
  } else if (sliderThatWasMoved == c7_a.get()) {
    //[UserSliderCode_c7_a] -- add your slider handling code here..
    p.c7_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c7_a]
  } else if (sliderThatWasMoved == c8_a.get()) {
    //[UserSliderCode_c8_a] -- add your slider handling code here..
    p.c8_a = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c8_a]
  } else if (sliderThatWasMoved == inputGain.get()) {
    //[UserSliderCode_inputGain] -- add your slider handling code here..
    p.inputGain = sliderThatWasMoved->getValue();
    //[/UserSliderCode_inputGain]
  } else if (sliderThatWasMoved == c1_b.get()) {
    //[UserSliderCode_c1_b] -- add your slider handling code here..
    p.c1_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c1_b]
  } else if (sliderThatWasMoved == c2_b.get()) {
    //[UserSliderCode_c2_b] -- add your slider handling code here..
    p.c2_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c2_b]
  } else if (sliderThatWasMoved == c3_b.get()) {
    //[UserSliderCode_c3_b] -- add your slider handling code here..
    p.c3_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c3_b]
  } else if (sliderThatWasMoved == c4_b.get()) {
    //[UserSliderCode_c4_b] -- add your slider handling code here..
    p.c4_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c4_b]
  } else if (sliderThatWasMoved == c5_b.get()) {
    //[UserSliderCode_c5_b] -- add your slider handling code here..
    p.c5_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c5_b]
  } else if (sliderThatWasMoved == c6_b.get()) {
    //[UserSliderCode_c6_b] -- add your slider handling code here..
    p.c6_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c6_b]
  } else if (sliderThatWasMoved == c7_b.get()) {
    //[UserSliderCode_c7_b] -- add your slider handling code here..
    p.c7_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c7_b]
  } else if (sliderThatWasMoved == c8_b.get()) {
    //[UserSliderCode_c8_b] -- add your slider handling code here..
    p.c8_b = sliderThatWasMoved->getValue();
    //[/UserSliderCode_c8_b]
  }

  //[UsersliderValueChanged_Post]
  curveComponent->repaint();
  waveformComponent->repaint();
  //[/UsersliderValueChanged_Post]
}

//[MiscUserCode] You can add your own definitions of your custom methods or any
//other code here...
void MainComponent::timerCallback() {
  // TODO: mach das nicht...
  repaint();
}
//[/MiscUserCode]

//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public juce::Component, private juce::Timer" constructorParams="SAUNDAudioProcessor&amp; p"
                 variableInitialisers="p(p)" snapPixels="4" snapActive="1" snapShown="1"
                 overlayOpacity="0.330" fixedSize="1" initialWidth="1000" initialHeight="600">
  <BACKGROUND backgroundColour="ffffffff">
    <TEXT pos="876 16 104 30" fill="solid: ff000000" hasStroke="0" text="output gain"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="40 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#185;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="0 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="120 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#178;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="80 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="200 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#179;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="160 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="280 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8308;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="240 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="356 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8309;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="316 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="436 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8310;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="396 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="516 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8311;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="476 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="596 0 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8312;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="556 120 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="776 16 104 30" fill="solid: ff000000" hasStroke="0" text="input gain"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <RECT pos="952 152 12 12" fill="solid: ffffffff" hasStroke="1" stroke="2, mitered, butt"
          strokeColour="solid: ff000000"/>
    <TEXT pos="896 144 52 26" fill="solid: ff000000" hasStroke="0" text="clipping"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="40 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#185;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="0 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="120 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#178;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="80 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="200 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#179;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="160 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="280 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8308;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="240 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="356 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8309;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="316 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="436 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8310;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="396 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="516 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8311;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="476 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="596 140 32 30" fill="solid: ff000000" hasStroke="0" text="x&#8312;"
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
    <TEXT pos="556 260 32 36" fill="solid: ff000000" hasStroke="0" text="c = "
          fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
          italic="0" justification="36"/>
  </BACKGROUND>
  <SLIDER name="outputGain" id="aabad198ccd24845" memberName="outputGain"
          virtualName="" explicitFocusOrder="0" pos="884 48 88 80" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c1_a" id="2372eb347ad0ba8f" memberName="c1_a" virtualName=""
          explicitFocusOrder="0" pos="32 20 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c2_a" id="27814a7076c61885" memberName="c2_a" virtualName=""
          explicitFocusOrder="0" pos="112 20 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c3_a" id="93c33a2394ed8221" memberName="c3_a" virtualName=""
          explicitFocusOrder="0" pos="191 20 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c4_a" id="163990fa99e38305" memberName="c4_a" virtualName=""
          explicitFocusOrder="0" pos="271 20 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c5_a" id="6666ee13492afe96" memberName="c5_a" virtualName=""
          explicitFocusOrder="0" pos="349 19 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c6_a" id="312eaa8d22c63bac" memberName="c6_a" virtualName=""
          explicitFocusOrder="0" pos="429 19 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c7_a" id="c70eaf579fff9605" memberName="c7_a" virtualName=""
          explicitFocusOrder="0" pos="508 19 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c8_a" id="27324f1467fc1bee" memberName="c8_a" virtualName=""
          explicitFocusOrder="0" pos="588 19 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="inputGain" id="f8ab5c4293d52b47" memberName="inputGain"
          virtualName="" explicitFocusOrder="0" pos="784 48 88 80" textboxtext="ff000000"
          min="0.0" max="8.0" int="0.001" style="Rotary" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c1_b" id="bec6aafc60813876" memberName="c1_b" virtualName=""
          explicitFocusOrder="0" pos="31 161 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c2_b" id="54c3ee4089e7e7a" memberName="c2_b" virtualName=""
          explicitFocusOrder="0" pos="111 161 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c3_b" id="b6d8d42a71eddb83" memberName="c3_b" virtualName=""
          explicitFocusOrder="0" pos="190 161 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c4_b" id="7943d8859fb36e7d" memberName="c4_b" virtualName=""
          explicitFocusOrder="0" pos="270 161 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c5_b" id="69f9104c51ce1429" memberName="c5_b" virtualName=""
          explicitFocusOrder="0" pos="348 160 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c6_b" id="d935b1eecb80529b" memberName="c6_b" virtualName=""
          explicitFocusOrder="0" pos="428 160 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c7_b" id="99b7082ad8a7d7ff" memberName="c7_b" virtualName=""
          explicitFocusOrder="0" pos="507 160 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <SLIDER name="c8_b" id="531d60624f703c50" memberName="c8_b" virtualName=""
          explicitFocusOrder="0" pos="587 160 46 128" textboxtext="ff000000"
          min="0.0" max="1.0" int="0.001" style="LinearVertical" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif

//[EndFile] You can add extra defines here...
//[/EndFile]
