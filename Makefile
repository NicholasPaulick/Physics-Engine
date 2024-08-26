# Define the compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude

# Define the target executable
TARGET = obj/AllTests_test

# Define the object files
OBJ = obj/Matrix2x2.o obj/Matrix3x3.o obj/Vector2D.o obj/Vector3D.o obj/Quaternion.o \
	  obj/Timer.o \
      obj/AllTests.o \
      obj/Matrix2x2Test.o obj/Matrix3x3Test.o obj/Vector2DTest.o obj/Vector3DTest.o obj/QuaternionTest.o \
	  obj/TimerTest.o

# Default rule
all: $(TARGET)

# Rule to create the obj directory if it doesn't exist
obj:
	mkdir -p obj

# Rule to link the object files into the final executable
$(TARGET): obj $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

# Rule to compile src/core .cpp files into .o files
obj/%.o: src/core/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile src/utils .cpp files into .o files
obj/%.o: src/utils/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to compile tests .cpp files into .o files
obj/%.o: tests/%.cpp | obj
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf obj/
