# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Directories
SRC = src
OBJ_DIR = obj
TEST_DIR = tests

# Source files
SRC_FILES = $(wildcard $(SRC)/*/*.cpp)

# Object files for the main library
OBJS = $(patsubst $(SRC)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Object files for tests
TEST_SRC_FILES = $(wildcard $(TEST_DIR)/*/*.cpp) $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRC_FILES))

# Output library
LIB = libPhysicsEngine.a

# Test target executable
TEST_TARGET = $(OBJ_DIR)/AllTests_test

# Default rule to build the library
all: $(LIB)

# Rule to create the necessary directory structure
$(OBJ_DIR)/%.o: $(SRC)/%.cpp | create_dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile test files into object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp | create_dirs
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create necessary directories for object files
create_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/core
	@mkdir -p $(OBJ_DIR)/physics
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/tests

# Rule to create the library
$(LIB): $(OBJS)
	ar rcs $@ $^

# Rule to build and run the test executable
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Rule to link test objects into the test executable
$(TEST_TARGET): $(LIB) $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_OBJS) $(LIB)

# Clean up build files
clean:
	rm -rf $(OBJ_DIR) $(LIB) $(TEST_TARGET)
