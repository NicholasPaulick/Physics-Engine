#include "../include/core/Matrix2x2.h"
#include <cassert>
#include <iostream>
#include <cmath>

const double EPSILON = 1e-6;

bool approxEqual(double a, double b) {
    return std::abs(a - b) < EPSILON;
}

void testMatrix2x2Addition() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(5, 6, 7, 8);
    Matrix2x2 result = m1 + m2;
    assert(approxEqual(result.get(0, 0), 6) && approxEqual(result.get(0, 1), 8));
    assert(approxEqual(result.get(1, 0), 10) && approxEqual(result.get(1, 1), 12));
    std::cout << "testMatrixAddition passed!" << std::endl;
}

void testMatrix2x2Subtraction() {
    Matrix2x2 m1(5, 6, 7, 8);
    Matrix2x2 m2(1, 2, 3, 4);
    Matrix2x2 result = m1 - m2;
    assert(approxEqual(result.get(0, 0), 4) && approxEqual(result.get(0, 1), 4));
    assert(approxEqual(result.get(1, 0), 4) && approxEqual(result.get(1, 1), 4));
    std::cout << "testMatrixSubtraction passed!" << std::endl;
}

void testMatrix2x2Multiplication() {
    Matrix2x2 m1(1, 2, 3, 4);
    Matrix2x2 m2(2, 0, 1, 2);
    Matrix2x2 result = m1 * m2;
    assert(approxEqual(result.get(0, 0), 4) && approxEqual(result.get(0, 1), 4));
    assert(approxEqual(result.get(1, 0), 10) && approxEqual(result.get(1, 1), 8));
    std::cout << "testMatrixMultiplication passed!" << std::endl;
}

void testMatrix2x2VectorMultiplication() {
    Matrix2x2 m(1, 2, 3, 4);
    Vector2D v(1, 1);
    Vector2D result = m * v;
    assert(approxEqual(result.getX(), 3) && approxEqual(result.getY(), 7));
    std::cout << "testMatrixVectorMultiplication passed!" << std::endl;
}

void testMatrix2x2Determinant() {
    Matrix2x2 m(1, 2, 3, 4);
    double det = m.determinant();
    assert(approxEqual(det, -2));
    std::cout << "testMatrixDeterminant passed!" << std::endl;
}

void testMatrix2x2Inverse() {
    Matrix2x2 m(4, 7, 2, 6);
    Matrix2x2 inv = m.inverse();
    assert(approxEqual(inv.get(0, 0), 0.6) && approxEqual(inv.get(0, 1), -0.7));
    assert(approxEqual(inv.get(1, 0), -0.2) && approxEqual(inv.get(1, 1), 0.4));
    std::cout << "testMatrixInverse passed!" << std::endl;
}

void testMatrix2x2Transpose() {
    Matrix2x2 m(1, 2, 3, 4);
    Matrix2x2 transposed = m.transpose();
    assert(approxEqual(transposed.get(0, 0), 1) && approxEqual(transposed.get(0, 1), 3));
    assert(approxEqual(transposed.get(1, 0), 2) && approxEqual(transposed.get(1, 1), 4));
    std::cout << "testMatrixTranspose passed!" << std::endl;
}

void testMatrix2x2Rotation() {
    double angle = M_PI / 4; // 45 degrees
    Matrix2x2 rotationMatrix = Matrix2x2::rotation(angle);
    assert(approxEqual(rotationMatrix.get(0, 0), std::cos(angle)));
    assert(approxEqual(rotationMatrix.get(0, 1), -std::sin(angle)));
    assert(approxEqual(rotationMatrix.get(1, 0), std::sin(angle)));
    assert(approxEqual(rotationMatrix.get(1, 1), std::cos(angle)));
    std::cout << "testMatrix2x2Rotation passed!" << std::endl;
}

void testMatrix2x2Scale() {
    Matrix2x2 scaleMatrix = Matrix2x2::scale(2, 3);
    assert(approxEqual(scaleMatrix.get(0, 0), 2));
    assert(approxEqual(scaleMatrix.get(0, 1), 0));
    assert(approxEqual(scaleMatrix.get(1, 0), 0));
    assert(approxEqual(scaleMatrix.get(1, 1), 3));
    std::cout << "testMatrix2x2Scale passed!" << std::endl;
}

int testMatrix2x2() {
    testMatrix2x2Addition();
    testMatrix2x2Subtraction();
    testMatrix2x2Multiplication();
    testMatrix2x2VectorMultiplication();
    testMatrix2x2Determinant();
    testMatrix2x2Inverse();
    testMatrix2x2Transpose();
    testMatrix2x2Rotation();
    testMatrix2x2Scale();
    std::cout << "Matrix2x2 Tests Done\n" << std::endl;
    return 0;
}