# Development Guide

## Running Tests

This project uses `uv` for Python dependency management and `pytest` for testing the cookiecutter template.

### Prerequisites

- Install `uv`: https://github.com/astral-sh/uv

### Running All Tests

By default, slow tests (like CMake configuration) are skipped:

```bash
uv run pytest
```

### Running Tests with Verbose Output

```bash
uv run pytest -v
```

### Running All Tests Including Slow Tests

Slow tests fetch JUCE from GitHub and can take 30+ seconds:

```bash
uv run pytest -v -m slow
# OR run all tests
uv run pytest -v -m ''
```

### Running Specific Tests

```bash
# Run a specific test file
uv run pytest tests/test_template.py

# Run a specific test function
uv run pytest tests/test_template.py::test_template_generates_successfully
```

### Running Tests with Output

```bash
# Show print statements
uv run pytest -s

# Show verbose output with print statements
uv run pytest -v -s
```

## Test Coverage

The test suite validates:

1. **Template Generation** - Cookiecutter generates without errors
2. **File Existence** - All expected files are created
3. **Variable Substitution** - Plugin name, company name, etc. are correctly replaced
4. **Conditional Logic** - VST2 configuration is conditionally included based on user input
5. **CMake Configuration** - Generated CMakeLists.txt is syntactically valid

## Manual Testing

To manually test the template:

```bash
# Generate a test project
cookiecutter . --output-dir /tmp/test-output

# Build the generated project
cd /tmp/test-output/your-plugin-name
cmake -B build
cmake --build build --config Debug
```

## Project Structure

```
juce-starter-pack/
├── pyproject.toml                          # uv/pytest configuration
├── tests/
│   ├── __init__.py
│   └── test_template.py                    # Template tests
├── {{cookiecutter.plugin_name_lowercase}}/ # Cookiecutter template
│   ├── CMakeLists.txt                      # Template CMake config
│   ├── src/                                # Template source files
│   └── ...
└── cookiecutter.json                       # Template variables
```
