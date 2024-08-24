#ifndef VECTOR3D_H
#define VECTOR3D_H

class Vector3D {
public:
    float x, y, z;

    Vector3D(float x = 0, float y = 0, float z = 0);

    Vector3D operator+(const Vector3D& other) const;
    Vector3D operator-(const Vector3D& other) const;
    Vector3D operator*(float scalar) const;
    Vector3D operator/(float scalar) const;

    float dot(const Vector3D& other) const;
    Vector3D cross(const Vector3D& other) const;
    float magnitude() const;
    Vector3D normalize() const;

    static float distance(const Vector3D& a, const Vector3D& b);

    void print() const;
};

#endif
