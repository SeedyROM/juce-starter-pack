# JUCE Plugin Starter Pack

A cookiecutter template for creating JUCE audio plugins with VST2/VST3/AU/Standalone support.

## Features

- **Modern CMake setup** - Uses FetchContent to automatically download JUCE
- **Multiple plugin formats** - VST2, VST3, AU, and Standalone support
- **VST2 SDK integration** - Git submodule setup for VST2 support
- **Basic UI framework** - Minimal plugin editor with branded top bar
- **Development workflow** - Build script for rapid iteration with Element.app
- **Clean project structure** - Organized source layout ready for expansion

## Usage

### Prerequisites

- Python 3.x
- cookiecutter (`pip install cookiecutter`)
- CMake 3.22+
- C++17 compatible compiler

### Creating a New Plugin

```bash
# Create a new plugin from this template
cookiecutter /Users/zack/Workspace/dsp/juce-starter-pack

# Follow the prompts to configure your plugin:
# - plugin_name: Your plugin name (e.g., "MyAwesomePlugin")
# - company_name: Your company name
# - author_name: Your name
# - author_email: Your email
# - etc.
```

### After Generation

```bash
cd your-plugin-name

# Initialize git repository
git init
git add .
git commit -m "Initial commit from JUCE starter template"

# If using VST2, initialize the submodule
git submodule update --init --recursive

# Configure and build
cmake -B build
cmake --build build --config Release
```

## Template Structure

The generated project includes:

- **PluginProcessor** - Basic audio processor with stereo I/O
- **PluginEditor** - Minimal editor with top bar
- **TopBar component** - Simple branded header with logo
- **Build scripts** - Development workflow automation
- **CMake configuration** - Modern CMake with JUCE FetchContent

## Customization

After generating your project:

1. Replace `assets/images/logo.png` with your logo
2. Implement your DSP in `PluginProcessor::processBlock()`
3. Add UI components in `PluginEditor`
4. Update plugin metadata in `CMakeLists.txt`

## Development Workflow

The template includes a build script for rapid testing with Element.app:

```bash
# Configure Element project (optional)
cp scripts/element_project.conf.example scripts/element_project.conf
# Edit with your .els project path

# Build and reload
./scripts/element_dev.sh
```

## Based On

This template was extracted from the zplanar project, keeping only the generic infrastructure and removing application-specific DSP code.

## License

[Your License Here]
