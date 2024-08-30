#include "Vector2DTest.h"
#include "../include/core/Vector2D.h"
#include <cassert>
#include <iostream>
#include <cmath>

void testVectorAddition() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    Vector2D result = v1 + v2;
    assert(approxEqual(result.getX(), 4.0) && approxEqual(result.getY(), 6.0));
    std::cout << "testVectorAddition passed!" << std::endl;
}

void testVectorSubtraction() {
    Vector2D v1(5.0, 7.0);
    Vector2D v2(2.0, 3.0);
    Vector2D result = v1 - v2;
    assert(approxEqual(result.getX(), 3.0) && approxEqual(result.getY(), 4.0));
    std::cout << "testVectorSubtraction passed!" << std::endl;
}

void testVectorMultiplication() {
    Vector2D v(2.0, 3.0);
    Vector2D result = v * 2.0;
    assert(approxEqual(result.getX(), 4.0) && approxEqual(result.getY(), 6.0));
    std::cout << "testVectorMultiplication passed!" << std::endl;
}

void testVectorDivision() {
    Vector2D v(8.0, 6.0);
    Vector2D result = v / 2.0;
    assert(approxEqual(result.getX(), 4.0) && approxEqual(result.getY(), 3.0));
    std::cout << "testVectorDivision passed!" << std::endl;
}

void testVectorDotProduct() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    double result = v1.dot(v2);
    assert(approxEqual(result, 11.0));
    std::cout << "testVectorDotProduct passed!" << std::endl;
}

void testVectorCrossProduct() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);
    double result = v1.cross(v2);
    assert(approxEqual(result, -2.0));
    std::cout << "testVectorCrossProduct passed!" << std::endl;
}

void testVectorNormalization() {
    Vector2D v(3.0, 4.0);
    Vector2D result = v.normalize();
    assert(approxEqual(result.getX(), 0.6) && approxEqual(result.getY(), 0.8));
    std::cout << "testVectorNormalization passed!" << std::endl;
}

void testVectorMagnitude() {
    Vector2D v(3.0, 4.0);
    double result = v.magnitude();
    assert(approxEqual(result, 5.0));
    std::cout << "testVectorMagnitude passed!" << std::endl;
}

void testVectorDistance() {
    Vector2D v1(1.0, 1.0);
    Vector2D v2(4.0, 5.0);
    double result = Vector2D::distance(v1, v2);
    assert(approxEqual(result, 5.0));
    std::cout << "testVectorDistance passed!" << std::endl;
}

void testVectorAngle() {
    Vector2D v1(1.0, 0.0);
    Vector2D v2(0.0, 1.0);
    double result = v1.angle(v2);
    assert(approxEqual(result, M_PI / 2));
    std::cout << "testVectorAngle passed!" << std::endl;
}

int testVector2D() {
    testVectorAddition();
    testVectorSubtraction();
    testVectorMultiplication();
    testVectorDivision();
    testVectorDotProduct();
    testVectorCrossProduct();
    testVectorNormalization();
    testVectorMagnitude();
    testVectorDistance();
    testVectorAngle();
    std::cout << "Vector2D Tests Done\n" << std::endl;
    return 0;
}