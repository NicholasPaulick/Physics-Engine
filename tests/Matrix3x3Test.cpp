// Matrix3x3Test.cpp
#include "../include/core/Matrix3x3.h"
#include <cassert>
#include <iostream>
#include <cmath>

void testMatrix3x3Addition() {
    float a_elements[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };
    float b_elements[3][3] = {
        {9.0f, 8.0f, 7.0f},
        {6.0f, 5.0f, 4.0f},
        {3.0f, 2.0f, 1.0f}
    };
    Matrix3x3 a(a_elements);
    Matrix3x3 b(b_elements);
    Matrix3x3 result = a + b;

    assert(result.m[0][0] == 10.0f && result.m[0][1] == 10.0f && result.m[0][2] == 10.0f);
    assert(result.m[1][0] == 10.0f && result.m[1][1] == 10.0f && result.m[1][2] == 10.0f);
    assert(result.m[2][0] == 10.0f && result.m[2][1] == 10.0f && result.m[2][2] == 10.0f);
    std::cout << "testMatrix3x3Addition passed!" << std::endl;
}

void testMatrix3x3Subtraction() {
    float a_elements[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };
    float b_elements[3][3] = {
        {9.0f, 8.0f, 7.0f},
        {6.0f, 5.0f, 4.0f},
        {3.0f, 2.0f, 1.0f}
    };
    Matrix3x3 a(a_elements);
    Matrix3x3 b(b_elements);
    Matrix3x3 result = a - b;

    assert(result.m[0][0] == -8.0f && result.m[0][1] == -6.0f && result.m[0][2] == -4.0f);
    assert(result.m[1][0] == -2.0f && result.m[1][1] == 0.0f && result.m[1][2] == 2.0f);
    assert(result.m[2][0] == 4.0f && result.m[2][1] == 6.0f && result.m[2][2] == 8.0f);
    std::cout << "testMatrix3x3Subtraction passed!" << std::endl;
}

void testMatrix3x3Multiplication() {
    float a_elements[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };
    float b_elements[3][3] = {
        {9.0f, 8.0f, 7.0f},
        {6.0f, 5.0f, 4.0f},
        {3.0f, 2.0f, 1.0f}
    };
    Matrix3x3 a(a_elements);
    Matrix3x3 b(b_elements);
    Matrix3x3 result = a * b;

    assert(result.m[0][0] == 30.0f && result.m[0][1] == 24.0f && result.m[0][2] == 18.0f);
    assert(result.m[1][0] == 84.0f && result.m[1][1] == 69.0f && result.m[1][2] == 54.0f);
    assert(result.m[2][0] == 138.0f && result.m[2][1] == 114.0f && result.m[2][2] == 90.0f);
    std::cout << "testMatrix3x3Multiplication passed!" << std::endl;
}

void testMatrix3x3VectorMultiplication() {
    float a_elements[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };
    Matrix3x3 a(a_elements);
    Vector3D v(1.0f, 2.0f, 3.0f);
    Vector3D result = a * v;

    assert(result.x == 14.0f && result.y == 32.0f && result.z == 50.0f);
    std::cout << "testMatrix3x3VectorMultiplication passed!" << std::endl;
}

void testMatrix3x3Determinant() {
    float a_elements[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };
    Matrix3x3 a(a_elements);
    float result = a.determinant();

    assert(result == 0.0f);
    std::cout << "testMatrix3x3Determinant passed!" << std::endl;
}

void testMatrix3x3Inverse() {
    float a_elements[3][3] = {
        {0.0f, 1.0f, 1.0f},
        {1.0f, 1.0f, 1.0f},
        {1.0f, 1.0f, 0.0f}
    };
    Matrix3x3 a(a_elements);
    Matrix3x3 inv;

    try {
        inv = a.inverse();
        float expected_elements[3][3] = {
            {-1.0f, 1.0f, 0.0f},
            {1.0f, -1.0f, 1.0f},
            {0.0f, 1.0f, -1.0f}
        };
        Matrix3x3 expected(expected_elements);

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                assert(std::fabs(inv.m[i][j] - expected.m[i][j]) < 1e-5f);
            }
        }

        std::cout << "testMatrix3x3Inverse passed!" << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << "testMatrix3x3Inverse failed: " << e.what() << std::endl;
    }
}


void testMatrix3x3Transpose() {
    float a_elements[3][3] = {
        {1.0f, 2.0f, 3.0f},
        {4.0f, 5.0f, 6.0f},
        {7.0f, 8.0f, 9.0f}
    };
    Matrix3x3 a(a_elements);
    Matrix3x3 result = a.transpose();

    assert(result.m[0][0] == 1.0f && result.m[0][1] == 4.0f && result.m[0][2] == 7.0f);
    assert(result.m[1][0] == 2.0f && result.m[1][1] == 5.0f && result.m[1][2] == 8.0f);
    assert(result.m[2][0] == 3.0f && result.m[2][1] == 6.0f && result.m[2][2] == 9.0f);
    std::cout << "testMatrix3x3Transpose passed!" << std::endl;
}

int testMatrix3x3() {
    testMatrix3x3Addition();
    testMatrix3x3Subtraction();
    testMatrix3x3Multiplication();
    testMatrix3x3VectorMultiplication();
    testMatrix3x3Determinant();
    testMatrix3x3Inverse();
    testMatrix3x3Transpose();

    std::cout << "Matrix3x3 Tests Done\n" << std::endl;
    return 0;
}
