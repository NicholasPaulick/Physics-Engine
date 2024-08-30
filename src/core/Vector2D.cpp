#include "../include/core/Vector2D.h"
#include <iostream>
#include <cmath>

Vector2D::Vector2D(double x, double y) : x(x), y(y) {}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator-() const {
    return Vector2D(-x, -y);
}

Vector2D Vector2D::operator*(double scalar) const {
    return Vector2D(x * scalar, y * scalar);
}

Vector2D Vector2D::operator/(double scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    return Vector2D(x / scalar, y / scalar);
}

Vector2D& Vector2D::operator+=(const Vector2D& other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vector2D& Vector2D::operator-=(const Vector2D& other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vector2D& Vector2D::operator*=(double scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2D& Vector2D::operator/=(double scalar) {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }
    x /= scalar;
    y /= scalar;
    return *this;
}

double Vector2D::dot(const Vector2D& other) const {
    return x * other.x + y * other.y;
}

double Vector2D::cross(const Vector2D& other) const {
    return x * other.y - y * other.x;
}

double Vector2D::magnitude() const {
    return std::sqrt(x * x + y * y);
}

Vector2D Vector2D::normalize() const {
    double mag = magnitude();
    if (mag == 0) {
        throw std::runtime_error("Cannot normalize zero vector");
    }
    return *this / mag;
}

double Vector2D::angle(const Vector2D& other) const {
    return std::atan2(cross(other), dot(other));
}

double Vector2D::distance(const Vector2D& a, const Vector2D& b) {
    return (a - b).magnitude();
}

double Vector2D::getX() const {
    return x;
}

double Vector2D::getY() const {
    return y;
}

void Vector2D::print() const {
    std::cout << "Vector2D(" << x << ", " << y << ")" << std::endl;
}
