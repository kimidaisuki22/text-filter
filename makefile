# Makefile for building a CMake project with release configuration

# Compiler and compiler flags
CXX := g++
CXX_FLAGS := -std=c++17 -O2

# CMake build directory
BUILD_DIR := build

# CMake release build options
CMAKE_OPTIONS := -DCMAKE_BUILD_TYPE=Release

# Targets
all: release

release: $(BUILD_DIR)
	@echo "Building the project in Release mode"
	cd $(BUILD_DIR) && cmake $(CMAKE_OPTIONS) ..
	$(MAKE) -C $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	@echo "Cleaning the project"
	rm -rf $(BUILD_DIR)

.PHONY: all release clean
