#include "core/Quaternion.h"
#include <cmath>
#include <stdexcept>

// Constructors
Quaternion::Quaternion() : w(1), x(0), y(0), z(0) {}
Quaternion::Quaternion(float w, float x, float y, float z) : w(w), x(x), y(y), z(z) {}

// Quaternion operations
Quaternion Quaternion::operator+(const Quaternion& q) const {
    return Quaternion(w + q.w, x + q.x, y + q.y, z + q.z);
}

Quaternion Quaternion::operator-(const Quaternion& q) const {
    return Quaternion(w - q.w, x - q.x, y - q.y, z - q.z);
}

Quaternion Quaternion::operator*(const Quaternion& q) const {
    return Quaternion(
        w * q.w - x * q.x - y * q.y - z * q.z,
        w * q.x + x * q.w + y * q.z - z * q.y,
        w * q.y - x * q.z + y * q.w + z * q.x,
        w * q.z + x * q.y - y * q.x + z * q.w
    );
}

Quaternion Quaternion::operator*(float scalar) const {
    return Quaternion(w * scalar, x * scalar, y * scalar, z * scalar);
}

Quaternion Quaternion::operator/(float scalar) const {
    if (scalar == 0) {
        throw std::runtime_error("Division by zero in quaternion division");
    }
    return Quaternion(w / scalar, x / scalar, y / scalar, z / scalar);
}

Quaternion Quaternion::conjugate() const {
    return Quaternion(w, -x, -y, -z);
}

Quaternion Quaternion::normalize() const {
    float mag = magnitude();
    if (mag == 0) {
        // Handle the case where the quaternion is zero to avoid division by zero
        return Quaternion(1, 0, 0, 0); // Return a default quaternion or handle as needed
    }
    return Quaternion(w / mag, x / mag, y / mag, z / mag);
}

float Quaternion::magnitude() const {
    return std::sqrt(w * w + x * x + y * y + z * z);
}

Quaternion Quaternion::inverse() const {
    float magnitudeSquared = magnitude() * magnitude();
    if (magnitudeSquared == 0) {
        throw std::runtime_error("Cannot invert a quaternion with zero magnitude");
    }
    return conjugate() / magnitudeSquared;
}

Vector3D Quaternion::operator*(const Vector3D& vec) const {
    Quaternion qVec(0, vec.getX(), vec.getY(), vec.getZ());
    Quaternion qRes = *this * qVec * conjugate();
    return Vector3D(qRes.getX(), qRes.getY(), qRes.getZ());
}


// Getter methods
float Quaternion::getW() const { return w; }
float Quaternion::getX() const { return x; }
float Quaternion::getY() const { return y; }
float Quaternion::getZ() const { return z; }
