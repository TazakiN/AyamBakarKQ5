CC := g++

CFLAGS := -Wall -Wextra -std=c++11
SRC_DIR := src
BUILD_DIR := bin

# Get all source files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)

# Generate object file names
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Target executable
TARGET := main

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean rule
clean:
	@rm -rf $(BUILD_DIR)/* $(TARGET)
