#pragma once

#include "PluginProcessor.h"
#include "components/brand/TopBar.h"

#include <juce_audio_processors/juce_audio_processors.h>

class {{cookiecutter.plugin_name}}AudioProcessorEditor : public juce::AudioProcessorEditor {
public:
  {{cookiecutter.plugin_name}}AudioProcessorEditor({{cookiecutter.plugin_name}}AudioProcessor &);
  ~{{cookiecutter.plugin_name}}AudioProcessorEditor() override;

  void paint(juce::Graphics &) override;
  void resized() override;

private:
  {{cookiecutter.plugin_name}}AudioProcessor &audioProcessor;

  // Components
  TopBar topBar;

  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR({{cookiecutter.plugin_name}}AudioProcessorEditor)
};
