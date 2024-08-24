#include "Vector2DTest.h"
#include "../include/core/Vector2D.h"
#include <cassert>
#include <iostream>

void testVectorAddition() {
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(3.0f, 4.0f);
    Vector2D result = v1 + v2;

    assert(result.x == 4.0f && result.y == 6.0f);
    std::cout << "testVectorAddition passed!" << std::endl;
}

void testVectorSubtraction() {
    Vector2D v1(5.0f, 7.0f);
    Vector2D v2(2.0f, 3.0f);
    Vector2D result = v1 - v2;

    assert(result.x == 3.0f && result.y == 4.0f);
    std::cout << "testVectorSubtraction passed!" << std::endl;
}

void testVectorMultiplication() {
    Vector2D v(2.0f, 3.0f);
    Vector2D result = v * 2.0f;

    assert(result.x == 4.0f && result.y == 6.0f);
    std::cout << "testVectorMultiplication passed!" << std::endl;
}

void testVectorDivision() {
    Vector2D v(8.0f, 6.0f);
    Vector2D result = v / 2.0f;

    assert(result.x == 4.0f && result.y == 3.0f);
    std::cout << "testVectorDivision passed!" << std::endl;
}

void testVectorDotProduct() {
    Vector2D v1(1.0f, 2.0f);
    Vector2D v2(3.0f, 4.0f);
    float result = v1.dot(v2);

    assert(result == 11.0f);
    std::cout << "testVectorDotProduct passed!" << std::endl;
}

void testVectorNormalization() {
    Vector2D v(3.0f, 4.0f);
    Vector2D result = v.normalize();

    assert(result.x == 0.6f && result.y == 0.8f);
    std::cout << "testVectorNormalization passed!" << std::endl;
}

void testVectorMagnitude() {
    Vector2D v(3.0f, 4.0f);
    float result = v.magnitude();

    assert(result == 5.0f);
    std::cout << "testVectorMagnitude passed!" << std::endl;
}

void testVectorDistance() {
    Vector2D v1(1.0f, 1.0f);
    Vector2D v2(4.0f, 5.0f);
    float result = Vector2D::distance(v1, v2);

    assert(result == 5.0f);
    std::cout << "testVectorDistance passed!" << std::endl;
}

int testVector2D() {
    testVectorAddition();
    testVectorSubtraction();
    testVectorMultiplication();
    testVectorDivision();
    testVectorDotProduct();
    testVectorNormalization();
    testVectorMagnitude();
    testVectorDistance();

    std::cout << "Vector2D Test's Done\n" << std::endl;
    return 0;
}
