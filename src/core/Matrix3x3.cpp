// Matrix3x3.cpp
#include "../include/core/Matrix3x3.h"
#include <iostream>
#include <stdexcept>

// Constructors
Matrix3x3::Matrix3x3() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] = 0.0f;
}

Matrix3x3::Matrix3x3(float elements[3][3]) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            m[i][j] = elements[i][j];
}

// Matrix operations
Matrix3x3 Matrix3x3::operator+(const Matrix3x3& other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = m[i][j] + other.m[i][j];
    return result;
}

Matrix3x3 Matrix3x3::operator-(const Matrix3x3& other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            result.m[i][j] = m[i][j] - other.m[i][j];
    return result;
}

Matrix3x3 Matrix3x3::operator*(const Matrix3x3& other) const {
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.m[i][j] = 0.0f;
            for (int k = 0; k < 3; ++k) {
                result.m[i][j] += m[i][k] * other.m[k][j];
            }
        }
    }
    return result;
}

Vector3D Matrix3x3::operator*(const Vector3D& vector) const {
    return Vector3D(
        m[0][0] * vector.x + m[0][1] * vector.y + m[0][2] * vector.z,
        m[1][0] * vector.x + m[1][1] * vector.y + m[1][2] * vector.z,
        m[2][0] * vector.x + m[2][1] * vector.y + m[2][2] * vector.z
    );
}

// Determinant
float Matrix3x3::determinant() const {
    return m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1])
         - m[0][1] * (m[1][0] * m[2][2] - m[1][2] * m[2][0])
         + m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]);
}

// Inverse
Matrix3x3 Matrix3x3::inverse() const {
    float det = determinant();
    if (det == 0.0f) {
        throw std::runtime_error("Matrix is singular and cannot be inverted");
    }

    Matrix3x3 result;
    result.m[0][0] =  (m[1][1] * m[2][2] - m[1][2] * m[2][1]) / det;
    result.m[0][1] = -(m[0][1] * m[2][2] - m[0][2] * m[2][1]) / det;
    result.m[0][2] =  (m[0][1] * m[1][2] - m[0][2] * m[1][1]) / det;
    result.m[1][0] = -(m[1][0] * m[2][2] - m[1][2] * m[2][0]) / det;
    result.m[1][1] =  (m[0][0] * m[2][2] - m[0][2] * m[2][0]) / det;
    result.m[1][2] = -(m[0][0] * m[1][2] - m[0][2] * m[1][0]) / det;
    result.m[2][0] =  (m[1][0] * m[2][1] - m[1][1] * m[2][0]) / det;
    result.m[2][1] = -(m[0][0] * m[2][1] - m[0][1] * m[2][0]) / det;
    result.m[2][2] =  (m[0][0] * m[1][1] - m[0][1] * m[1][0]) / det;

    return result;
}

// Transpose
Matrix3x3 Matrix3x3::transpose() const {
    Matrix3x3 result;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            result.m[i][j] = m[j][i];
        }
    }
    return result;
}

// Utility functions
void Matrix3x3::print() const {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
