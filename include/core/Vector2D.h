#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <stdexcept>

class Vector2D {
private:
    double x, y;

public:
    Vector2D(double x = 0.0, double y = 0.0);

    // Basic vector operations
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator-() const;
    Vector2D operator*(double scalar) const;
    Vector2D operator/(double scalar) const;

    // Compound assignment operators
    Vector2D& operator+=(const Vector2D& other);
    Vector2D& operator-=(const Vector2D& other);
    Vector2D& operator*=(double scalar);
    Vector2D& operator/=(double scalar);

    // Dot product
    double dot(const Vector2D& other) const;

    // Cross product (for 2D vectors, returns a scalar)
    double cross(const Vector2D& other) const;

    // Magnitude of the vector
    double magnitude() const;

    // Normalize the vector
    Vector2D normalize() const;

    // Angle between two vectors
    double angle(const Vector2D& other) const;

    // Distance between two vectors
    static double distance(const Vector2D& a, const Vector2D& b);

    // Getters
    double getX() const;
    double getY() const;

    // Print the vector (for debugging)
    void print() const;
};

#endif // VECTOR2D_H