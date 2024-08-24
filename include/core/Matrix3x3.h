// Matrix3x3.h
#ifndef MATRIX3X3_H
#define MATRIX3X3_H

#include "Vector3D.h"

class Matrix3x3 {
public:
    float m[3][3];

    // Constructors
    Matrix3x3();
    Matrix3x3(float elements[3][3]);

    // Matrix operations
    Matrix3x3 operator+(const Matrix3x3& other) const;
    Matrix3x3 operator-(const Matrix3x3& other) const;
    Matrix3x3 operator*(const Matrix3x3& other) const;
    Vector3D operator*(const Vector3D& vector) const;

    // Determinant, inverse, and transpose
    float determinant() const;
    Matrix3x3 inverse() const;
    Matrix3x3 transpose() const;

    // Utility functions
    void print() const;
};

#endif // MATRIX3X3_H
