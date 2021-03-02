/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"
#include "PluginProcessor.h"


//==============================================================================
SAUNDAudioProcessorEditor::SAUNDAudioProcessorEditor(SAUNDAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p), mainComponent(p) {
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  addAndMakeVisible(mainComponent);
  setSize(1000, 600);
}

SAUNDAudioProcessorEditor::~SAUNDAudioProcessorEditor() {}

//==============================================================================
void SAUNDAudioProcessorEditor::paint(juce::Graphics &g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  // g.fillAll (getLookAndFeel().findColour
  // (juce::ResizableWindow::backgroundColourId));

  // g.setColour (juce::Colours::white);
  // g.setFont (15.0f);
  // g.drawFittedText ("Hello World!", getLocalBounds(),
  // juce::Justification::centred, 1);
}

void SAUNDAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
}
