#include "../include/core/Matrix2x2.h"
#include <iostream>
#include <cmath>

// Default constructor - Identity matrix
Matrix2x2::Matrix2x2()
    : m00(1), m01(0), m10(0), m11(1) {}

// Constructor with specified values
Matrix2x2::Matrix2x2(double m00, double m01, double m10, double m11)
    : m00(m00), m01(m01), m10(m10), m11(m11) {}

// Identity matrix
Matrix2x2 Matrix2x2::identity() {
    return Matrix2x2(1, 0, 0, 1);
}

// Rotation matrix
Matrix2x2 Matrix2x2::rotation(double angle) {
    double c = std::cos(angle);
    double s = std::sin(angle);
    return Matrix2x2(c, -s, s, c);
}

// Scale matrix
Matrix2x2 Matrix2x2::scale(double sx, double sy) {
    return Matrix2x2(sx, 0, 0, sy);
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
        m00 * vec.getX() + m01 * vec.getY(),
        m10 * vec.getX() + m11 * vec.getY()
    );
}

// Scalar multiplication
Matrix2x2 Matrix2x2::operator*(double scalar) const {
    return Matrix2x2(
        m00 * scalar, m01 * scalar,
        m10 * scalar, m11 * scalar
    );
}

// Compound assignment operators
Matrix2x2& Matrix2x2::operator+=(const Matrix2x2& other) {
    m00 += other.m00; m01 += other.m01;
    m10 += other.m10; m11 += other.m11;
    return *this;
}

Matrix2x2& Matrix2x2::operator-=(const Matrix2x2& other) {
    m00 -= other.m00; m01 -= other.m01;
    m10 -= other.m10; m11 -= other.m11;
    return *this;
}

Matrix2x2& Matrix2x2::operator*=(const Matrix2x2& other) {
    *this = *this * other;
    return *this;
}

Matrix2x2& Matrix2x2::operator*=(double scalar) {
    m00 *= scalar; m01 *= scalar;
    m10 *= scalar; m11 *= scalar;
    return *this;
}

// Determinant
double Matrix2x2::determinant() const {
    return m00 * m11 - m01 * m10;
}

// Inverse
Matrix2x2 Matrix2x2::inverse() const {
    double det = determinant();
    if (det == 0) {
        throw std::runtime_error("Matrix is not invertible");
    }
    double invDet = 1.0 / det;
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

// Getter
double Matrix2x2::get(int row, int col) const {
    if (row < 0 || row > 1 || col < 0 || col > 1) {
        throw std::out_of_range("Invalid matrix indices");
    }
    if (row == 0 && col == 0) return m00;
    if (row == 0 && col == 1) return m01;
    if (row == 1 && col == 0) return m10;
    return m11;
}

// Print (for debugging)
void Matrix2x2::print() const {
    std::cout << "[" << m00 << " " << m01 << "]\n";
    std::cout << "[" << m10 << " " << m11 << "]\n";
}