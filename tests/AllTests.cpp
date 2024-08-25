// AllTests.cpp
#include <iostream>
#include "Matrix2x2Test.h"
#include "Matrix3x3Test.h"
#include "Vector2DTest.h"
#include "Vector3DTest.h"
#include "QuaternionTest.h"

int main() {
    testMatrix2x2();
    testMatrix3x3();
    testVector2D();
    testVector3D();
    testQuaternion();

    std::cout << "All tests completed." << std::endl;
    return 0;
}
