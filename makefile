CC := g++
CFLAGS := -Wall -Wextra -std=c++11
SRC_DIR := src
BUILD_DIR := bin

# Get all source files (including those in 'utils')
SRCS := $(wildcard 	$(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)

# Generate object file names without subdirectories
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TARGET := main

# Default target
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Rule to build object files in the build directory
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

$(BUILD_DIR)/%: $(SRC_DIR)/%
	mkdir -p $@


# Clean rule for Unix shell
clean-unix:
	rm -f $(BUILD_DIR)/* $(TARGET)

# Clean rule for Windows shell
clean-windows:
	del /Q $(BUILD_DIR)\* $(TARGET)

clean: $(if $(OS),clean-windows,clean-unix)
