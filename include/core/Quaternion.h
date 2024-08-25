#ifndef QUATERNION_H
#define QUATERNION_H

class Quaternion {
private:
    float w, x, y, z;

public:
    // Constructors
    Quaternion();
    Quaternion(float w, float x, float y, float z);

    // Quaternion operations
    Quaternion operator+(const Quaternion& q) const;
    Quaternion operator-(const Quaternion& q) const;
    Quaternion operator*(const Quaternion& q) const;
    Quaternion operator*(float scalar) const; // Multiplication by a scalar
    Quaternion operator/(float scalar) const; // Division by a scalar
    Quaternion conjugate() const;
    Quaternion inverse() const;
    float norm() const;

    // Getter methods
    float getW() const;
    float getX() const;
    float getY() const;
    float getZ() const;
};

#endif // QUATERNION_H
