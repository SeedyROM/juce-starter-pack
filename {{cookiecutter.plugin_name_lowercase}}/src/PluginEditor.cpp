#include "PluginEditor.h"
#include "BinaryData.h"
#include "PluginProcessor.h"

{{cookiecutter.plugin_name}}AudioProcessorEditor::{{cookiecutter.plugin_name}}AudioProcessorEditor(
    {{cookiecutter.plugin_name}}AudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {

  // Add top bar
  addAndMakeVisible(topBar);

  setSize(800, 600);
}

{{cookiecutter.plugin_name}}AudioProcessorEditor::~{{cookiecutter.plugin_name}}AudioProcessorEditor() {}

void {{cookiecutter.plugin_name}}AudioProcessorEditor::paint(juce::Graphics &g) {
  g.fillAll(juce::Colour(0xff1a1a1a)); // Dark background
}

void {{cookiecutter.plugin_name}}AudioProcessorEditor::resized() {
  auto bounds = getLocalBounds();

  // Top bar (full width)
  topBar.setBounds(bounds.removeFromTop(50));

  // Main content area
  bounds.reduce(10, 10);

  // Add your component layout here
}
