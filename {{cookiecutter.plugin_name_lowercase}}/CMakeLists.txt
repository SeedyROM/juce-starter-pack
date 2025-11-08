cmake_minimum_required(VERSION 3.22)

project({{cookiecutter.plugin_name}} VERSION 0.1.0)

# Suppress developer warnings from JUCE
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON CACHE INTERNAL "")

set(CMAKE_CXX_STANDARD {{cookiecutter.cpp_standard}})
set(CMAKE_CXX_STANDARD_REQUIRED ON)

{% if cookiecutter.include_vst2 == "yes" -%}
# VST2 SDK Path - must be set BEFORE fetching JUCE
set(VST2_SDK_PATH "${CMAKE_CURRENT_SOURCE_DIR}/external/vst-2.4-sdk/vstsdk2.4" CACHE PATH "Path to VST2 SDK")

if(EXISTS "${VST2_SDK_PATH}/pluginterfaces/vst2.x/aeffect.h")
    message(STATUS "VST2 SDK found at: ${VST2_SDK_PATH}")
else()
    message(WARNING "VST2 SDK not found at: ${VST2_SDK_PATH}")
    message(WARNING "Run: git submodule update --init --recursive")
endif()

{% endif -%}
# Fetch JUCE from GitHub
include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG {{cookiecutter.juce_version}}
)
FetchContent_MakeAvailable(JUCE)

{% if cookiecutter.include_vst2 == "yes" -%}
# Set VST2 SDK path for JUCE
if(EXISTS "${VST2_SDK_PATH}/pluginterfaces/vst2.x/aeffect.h")
    juce_set_vst2_sdk_path("${VST2_SDK_PATH}")
endif()

{% endif -%}
# Define the plugin
juce_add_plugin({{cookiecutter.plugin_name}}
    COMPANY_NAME "{{cookiecutter.company_name}}"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    IS_MIDI_EFFECT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE {{cookiecutter.plugin_manufacturer_code}}
    PLUGIN_CODE {{cookiecutter.plugin_code}}
    FORMATS {% if cookiecutter.include_vst2 == "yes" %}VST {% endif %}{% if cookiecutter.include_vst3 == "yes" %}VST3 {% endif %}{% if cookiecutter.include_au == "yes" %}AU {% endif %}{% if cookiecutter.include_standalone == "yes" %}Standalone{% endif %}
    PRODUCT_NAME "{{cookiecutter.plugin_name}}"
)

# Add binary resources (fonts, images, etc)
juce_add_binary_data({{cookiecutter.plugin_name}}Assets SOURCES
    assets/images/logo.png
)

# Add source files
target_sources({{cookiecutter.plugin_name}} PRIVATE
    src/PluginProcessor.cpp
    src/PluginEditor.cpp
    src/components/brand/TopBar.cpp
)

# Set compile definitions
target_compile_definitions({{cookiecutter.plugin_name}} PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0
)

# Link JUCE modules
target_link_libraries({{cookiecutter.plugin_name}} PRIVATE
    juce::juce_audio_utils
    juce::juce_audio_processors
    juce::juce_graphics
    juce::juce_dsp
    {{cookiecutter.plugin_name}}Assets
PUBLIC
    juce::juce_recommended_config_flags
    juce::juce_recommended_lto_flags
    juce::juce_recommended_warning_flags
)
