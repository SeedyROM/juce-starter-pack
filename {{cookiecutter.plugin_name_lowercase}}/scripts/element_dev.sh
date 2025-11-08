#!/bin/bash

# Build and reload script for {{cookiecutter.plugin_name}} plugin testing with Element.app

# Check if local config exists for Element project path
CONFIG_FILE="scripts/element_project.conf"
ELEMENT_PROJECT=""

if [ -f "$CONFIG_FILE" ]; then
    ELEMENT_PROJECT=$(cat "$CONFIG_FILE")
fi

echo "🔨 Building {{cookiecutter.plugin_name}} plugin..."

# Build the plugin
cmake --build build --config Debug

# Check if build was successful
if [ $? -ne 0 ]; then
    echo "❌ Build failed! Fix errors before reloading."
    exit 1
fi

echo "✅ Build successful!"

# Check if Element is running
if pgrep -x "Element" > /dev/null; then
    echo "🔄 Restarting Element.app..."

    # Quit Element gracefully
    osascript -e 'quit app "Element"'

    # Wait a moment for it to fully quit
    sleep 1
else
    echo "▶️  Starting Element.app..."
fi

# Reopen Element with project if specified
if [ -n "$ELEMENT_PROJECT" ] && [ -f "$ELEMENT_PROJECT" ]; then
    echo "📂 Loading project: $ELEMENT_PROJECT"
    open -a Element "$ELEMENT_PROJECT"
else
    echo "📂 Opening Element (no project specified)"
    open -a Element
fi

echo "🎉 Done! Element is reloading with the updated plugin."
