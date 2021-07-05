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
  addAndMakeVisible(mainComponent);
  setSize(825, 440);
}

SAUNDAudioProcessorEditor::~SAUNDAudioProcessorEditor() {}

void SAUNDAudioProcessorEditor::paint(juce::Graphics & /*g*/) {}

void SAUNDAudioProcessorEditor::resized() {}

ApplicationCommandTarget *SAUNDAudioProcessorEditor::getNextCommandTarget() {
  return findFirstTargetParentComponent();
}

void SAUNDAudioProcessorEditor::getAllCommands(
    juce::Array<CommandID> &commands) {
  const CommandID ids[] = {Commands::UNDO, Commands::REDO};
  commands.addArray(ids, numElementsInArray(ids));
}

void SAUNDAudioProcessorEditor::getCommandInfo(CommandID commandID,
                                               ApplicationCommandInfo &result) {
  switch (commandID) {
  case Commands::UNDO:
    result.setInfo("Undo", "Undo last Step", "General", 0);
    result.addDefaultKeypress('z', ModifierKeys::ctrlModifier);
    break;
  case Commands::REDO:
    result.setInfo("Redo", "Redo last undone Step", "General", 0);
    result.addDefaultKeypress('y', ModifierKeys::ctrlModifier);
    break;
  }
}

bool SAUNDAudioProcessorEditor::perform(const InvocationInfo &info) {
  switch (info.commandID) {
  case Commands::UNDO:
    return audioProcessor.undoManager.undo();
  case Commands::REDO:
    return audioProcessor.undoManager.redo();
  }
  return false;
}