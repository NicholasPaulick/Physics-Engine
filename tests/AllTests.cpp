// AllTests.cpp
#include <iostream>
#include "core/Matrix2x2Test.h"
#include "core/Matrix3x3Test.h"
#include "core/Vector2DTest.h"
#include "core/Vector3DTest.h"
#include "core/QuaternionTest.h"
#include "utils/TimerTest.h"
#include "physics/RidgidBody2DTest.h"

int main() {
    testMatrix2x2();
    testMatrix3x3();
    testVector2D();
    testVector3D();
    testQuaternion();
    testTimer();
    testRigidBody2D();

    std::cout << "All tests completed." << std::endl;
    return 0;
}
