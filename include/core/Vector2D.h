#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {
public:
    float x, y;

    Vector2D(float x = 0.0f, float y = 0.0f);

    // Basic vector operations
    Vector2D operator+(const Vector2D& other) const;
    Vector2D operator-(const Vector2D& other) const;
    Vector2D operator*(float scalar) const;
    Vector2D operator/(float scalar) const;

    // Dot product
    float dot(const Vector2D& other) const;

    // Magnitude of the vector
    float magnitude() const;

    // Normalize the vector
    Vector2D normalize() const;

    // Distance between two vectors
    static float distance(const Vector2D& a, const Vector2D& b);

    // Print the vector (for debugging)
    void print() const;
};

#endif // VECTOR2D_H
