# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Directories
SRC_DIR = src
CORE_DIR = $(SRC_DIR)/core
TEST_DIR = tests
OBJ_DIR = obj

# Source files
CORE_SRC = $(wildcard $(CORE_DIR)/*.cpp)
TEST_SRC = $(wildcard $(TEST_DIR)/*.cpp)

# Object files
CORE_OBJ = $(patsubst $(SRC_DIR)/core/%.cpp,$(OBJ_DIR)/%.o,$(CORE_SRC))
TEST_OBJ = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRC))

# Executable
TEST_TARGET = obj/AllTests_test

# Default target
all: $(TEST_TARGET)

# Build the test target
$(TEST_TARGET): $(CORE_OBJ) $(TEST_OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(CORE_OBJ) $(TEST_OBJ)

# Object file compilation for core source files
$(OBJ_DIR)/%.o: $(CORE_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Object file compilation for test source files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -rf $(OBJ_DIR) $(TEST_TARGET)

.PHONY: all clean
