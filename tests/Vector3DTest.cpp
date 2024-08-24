#include "../include/core/Vector3D.h"
#include <cassert>
#include <iostream>
#include <cmath>

void testVector3DAddition() {
    Vector3D v1(1.0f, 2.0f, 3.0f);
    Vector3D v2(4.0f, 5.0f, 6.0f);
    Vector3D result = v1 + v2;

    assert(result.x == 5.0f && result.y == 7.0f && result.z == 9.0f);
    std::cout << "testVector3DAddition passed!" << std::endl;
}

void testVector3DSubtraction() {
    Vector3D v1(7.0f, 8.0f, 9.0f);
    Vector3D v2(1.0f, 2.0f, 3.0f);
    Vector3D result = v1 - v2;

    assert(result.x == 6.0f && result.y == 6.0f && result.z == 6.0f);
    std::cout << "testVector3DSubtraction passed!" << std::endl;
}

void testVector3DMultiplication() {
    Vector3D v(1.0f, 2.0f, 3.0f);
    Vector3D result = v * 3.0f;

    assert(result.x == 3.0f && result.y == 6.0f && result.z == 9.0f);
    std::cout << "testVector3DMultiplication passed!" << std::endl;
}

void testVector3DDivision() {
    Vector3D v(6.0f, 9.0f, 12.0f);
    Vector3D result = v / 3.0f;

    assert(result.x == 2.0f && result.y == 3.0f && result.z == 4.0f);
    std::cout << "testVector3DDivision passed!" << std::endl;
}

void testVector3DDotProduct() {
    Vector3D v1(1.0f, 2.0f, 3.0f);
    Vector3D v2(4.0f, 5.0f, 6.0f);
    float result = v1.dot(v2);

    assert(result == 32.0f);
    std::cout << "testVector3DDotProduct passed!" << std::endl;
}

void testVector3DCrossProduct() {
    Vector3D v1(1.0f, 0.0f, 0.0f);
    Vector3D v2(0.0f, 1.0f, 0.0f);
    Vector3D result = v1.cross(v2);

    assert(result.x == 0.0f && result.y == 0.0f && result.z == 1.0f);
    std::cout << "testVector3DCrossProduct passed!" << std::endl;
}

void testVector3DNormalization() {
    Vector3D v(3.0f, 4.0f, 0.0f);
    Vector3D result = v.normalize();

    assert(result.x == 0.6f && result.y == 0.8f && result.z == 0.0f);
    std::cout << "testVector3DNormalization passed!" << std::endl;
}

void testVector3DMagnitude() {
    Vector3D v(3.0f, 4.0f, 12.0f);
    float result = v.magnitude();

    assert(result == 13.0f);
    std::cout << "testVector3DMagnitude passed!" << std::endl;
}

void testVector3DDistance() {
    Vector3D v1(1.0f, 1.0f, 1.0f);
    Vector3D v2(4.0f, 5.0f, 9.0f);
    float result = Vector3D::distance(v1, v2);

    float expected = std::sqrt(89.0f); // Correct expected value
    float tolerance = 1e-5f;

    assert(std::fabs(result - expected) < tolerance);
    std::cout << "testVector3DDistance passed!" << std::endl;
}


int testVector3D() {
    testVector3DAddition();
    testVector3DSubtraction();
    testVector3DMultiplication();
    testVector3DDivision();
    testVector3DDotProduct();
    testVector3DCrossProduct();
    testVector3DNormalization();
    testVector3DMagnitude();
    testVector3DDistance();

    std::cout << "Vector3D Test's Done\n" << std::endl;
    return 0;
}
