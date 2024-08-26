#include "../include/core/Vector2D.h"
#include <iostream>
#include <cmath>

Vector2D::Vector2D(float x, float y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(float scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(float scalar) const {
    return Vector2D(x / scalar, y / scalar);
}

float Vector2D::dot(const Vector2D& other) const {
    return x * other.x + y * other.y;
}

float Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalize() const {
    float mag = magnitude();
    return Vector2D(x / mag, y / mag);
}

float Vector2D::distance(const Vector2D& a, const Vector2D& b) {
    return (a - b).magnitude();
}

float Vector2D::getX() const {
    return x;
}

float Vector2D::getY() const {
    return y;
}

void Vector2D::print() const {
    std::cout << "Vector2D(" << x << ", " << y << ")" << std::endl;
}
