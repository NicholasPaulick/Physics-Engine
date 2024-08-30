#ifndef MATRIX2X2_H
#define MATRIX2X2_H

#include "Vector2D.h"
#include <stdexcept>

class Matrix2x2 {
private:
    double m00, m01, m10, m11;

public:
    // Constructors
    Matrix2x2();
    Matrix2x2(double m00, double m01, double m10, double m11);

    // Static methods
    static Matrix2x2 identity();
    static Matrix2x2 rotation(double angle);
    static Matrix2x2 scale(double sx, double sy);

    // Basic matrix operations
    Matrix2x2 operator+(const Matrix2x2& other) const;
    Matrix2x2 operator-(const Matrix2x2& other) const;
    Matrix2x2 operator*(const Matrix2x2& other) const;
    Vector2D operator*(const Vector2D& vec) const;
    Matrix2x2 operator*(double scalar) const;

    // Compound assignment operators
    Matrix2x2& operator+=(const Matrix2x2& other);
    Matrix2x2& operator-=(const Matrix2x2& other);
    Matrix2x2& operator*=(const Matrix2x2& other);
    Matrix2x2& operator*=(double scalar);

    // Determinant and inverse
    double determinant() const;
    Matrix2x2 inverse() const;

    // Transpose
    Matrix2x2 transpose() const;

    // Getters
    double get(int row, int col) const;

    // Print (for debugging)
    void print() const;
};

#endif // MATRIX2X2_H