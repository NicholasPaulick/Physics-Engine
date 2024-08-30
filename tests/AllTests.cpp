// AllTests.cpp
#include <iostream>
#include "core/Matrix2x2Test.h"
#include "core/Vector2DTest.h"
#include "utils/TimerTest.h"
#include "physics/RigidBody2DTest.h"
#include "physics/Friction2DTest.h"

int main() {
    testMatrix2x2();
    testVector2D();
    testTimer();
    testRigidBody2D();

    std::cout << "All tests completed." << std::endl;
    return 0;
}