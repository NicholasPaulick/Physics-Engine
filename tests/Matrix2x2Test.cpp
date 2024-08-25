#include "../include/core/Matrix2x2.h"
#include <cassert>
#include <iostream>

void testMatrix2x2Addition() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);
    Matrix2x2 result = m1 + m2;

    assert(result.m00 == 6 && result.m01 == 8);
    assert(result.m10 == 10 && result.m11 == 12);
    std::cout << "testMatrixAddition passed!" << std::endl;
}

void testMatrix2x2Subtraction() {
    Matrix2x2 m1(5, 6, 7, 8);
    Matrix2x2 m2(1, 2, 3, 4);
    Matrix2x2 result = m1 - m2;

    assert(result.m00 == 4 && result.m01 == 4);
    assert(result.m10 == 4 && result.m11 == 4);
    std::cout << "testMatrixSubtraction passed!" << std::endl;
}

void testMatrix2x2Multiplication() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(2, 0, 1, 2);
    Matrix2x2 result = m1 * m2;

    assert(result.m00 == 4 && result.m01 == 4);
    assert(result.m10 == 10 && result.m11 == 8);
    std::cout << "testMatrixMultiplication passed!" << std::endl;
}

void testMatrix2x2VectorMultiplication() {
    Matrix2x2 m(1, 2, 3, 4);
    Vector2D v(1, 1);
    Vector2D result = m * v;

    assert(result.x == 3 && result.y == 7);
    std::cout << "testMatrixVectorMultiplication passed!" << std::endl;
}

void testMatrix2x2Determinant() {
    Matrix2x2 m(1, 2, 3, 4);
    float det = m.determinant();

    assert(det == -2);
    std::cout << "testMatrixDeterminant passed!" << std::endl;
}

void testMatrix2x2Inverse() {
    Matrix2x2 m(4, 7, 2, 6);
    Matrix2x2 inv = m.inverse();

    assert(inv.m00 == 0.6f && inv.m01 == -0.7f);
    assert(inv.m10 == -0.2f && inv.m11 == 0.4f);
    std::cout << "testMatrixInverse passed!" << std::endl;
}

void testMatrix2x2Transpose() {
    Matrix2x2 m(1, 2, 3, 4);
    Matrix2x2 transposed = m.transpose();

    assert(transposed.m00 == 1 && transposed.m01 == 3);
    assert(transposed.m10 == 2 && transposed.m11 == 4);
    std::cout << "testMatrixTranspose passed!" << std::endl;
}

int testMatrix2x2() {
    testMatrix2x2Addition();
    testMatrix2x2Subtraction();
    testMatrix2x2Multiplication();
    testMatrix2x2VectorMultiplication();
    testMatrix2x2Determinant();
    testMatrix2x2Inverse();
    testMatrix2x2Transpose();

    std::cout << "Matrix2x2 Tests Done\n"<< std::endl;
    return 0;
}
