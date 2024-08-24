#include "../include/core/Matrix2x2.h"
#include <iostream>
#include <stdexcept>

// Default constructor - Identity matrix
Matrix2x2::Matrix2x2() 
    : m00(1), m01(0), m10(0), m11(1) {}

// Constructor with specified values
Matrix2x2::Matrix2x2(float m00, float m01, float m10, float m11)
    : m00(m00), m01(m01), m10(m10), m11(m11) {}

// Identity matrix
Matrix2x2 Matrix2x2::identity() {
    return Matrix2x2(1, 0, 0, 1);
}

// Addition
Matrix2x2 Matrix2x2::operator+(const Matrix2x2& other) const {
    return Matrix2x2(
        m00 + other.m00, m01 + other.m01,
        m10 + other.m10, m11 + other.m11
    );
}

// Subtraction
Matrix2x2 Matrix2x2::operator-(const Matrix2x2& other) const {
    return Matrix2x2(
        m00 - other.m00, m01 - other.m01,
        m10 - other.m10, m11 - other.m11
    );
}

// Matrix multiplication
Matrix2x2 Matrix2x2::operator*(const Matrix2x2& other) const {
    return Matrix2x2(
        m00 * other.m00 + m01 * other.m10, m00 * other.m01 + m01 * other.m11,
        m10 * other.m00 + m11 * other.m10, m10 * other.m01 + m11 * other.m11
    );
}

// Matrix-vector multiplication
Vector2D Matrix2x2::operator*(const Vector2D& vec) const {
    return Vector2D(
        m00 * vec.x + m01 * vec.y,
        m10 * vec.x + m11 * vec.y
    );
}

// Scalar multiplication
Matrix2x2 Matrix2x2::operator*(float scalar) const {
    return Matrix2x2(
        m00 * scalar, m01 * scalar,
        m10 * scalar, m11 * scalar
    );
}

// Determinant
float Matrix2x2::determinant() const {
    return m00 * m11 - m01 * m10;
}

// Inverse
Matrix2x2 Matrix2x2::inverse() const {
    float det = determinant();
    if (det == 0) {
        throw std::runtime_error("Matrix is not invertible");
    }
    float invDet = 1.0f / det;
    return Matrix2x2(
        m11 * invDet, -m01 * invDet,
        -m10 * invDet, m00 * invDet
    );
}

// Transpose
Matrix2x2 Matrix2x2::transpose() const {
    return Matrix2x2(
        m00, m10,
        m01, m11
    );
}

// Print (for debugging)
void Matrix2x2::print() const {
    std::cout << "[" << m00 << " " << m01 << "]\n";
    std::cout << "[" << m10 << " " << m11 << "]\n";
}
