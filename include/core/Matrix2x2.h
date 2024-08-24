#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include "Vector2D.h"

class Matrix2x2 {
public:
    // Matrix elements
    float m00, m01;
    float m10, m11;

    // Constructors
    Matrix2x2();
    Matrix2x2(float m00, float m01, float m10, float m11);

    // Identity matrix
    static Matrix2x2 identity();

    // Basic matrix operations
    Matrix2x2 operator+(const Matrix2x2& other) const;
    Matrix2x2 operator-(const Matrix2x2& other) const;
    Matrix2x2 operator*(const Matrix2x2& other) const;
    Vector2D operator*(const Vector2D& vec) const;
    Matrix2x2 operator*(float scalar) const;

    // Determinant and inverse
    float determinant() const;
    Matrix2x2 inverse() const;

    // Transpose
    Matrix2x2 transpose() const;

    // Print (for debugging)
    void print() const;
};

#endif // MATRIX2X2_H
