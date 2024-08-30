#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "../include/core/Vector2D.h"
#include "../include/core/Matrix2x2.h"
#include <vector>

class RigidBody2D {
private:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    double mass;
    double angle;
    double angularVelocity;
    double angularAcceleration;
    double momentOfInertia;
    Vector2D force;
    double torque;
    std::vector<Vector2D> shape; // For collision detection
    bool isStatic; // For immovable objects

public:
    RigidBody2D(const Vector2D& position = Vector2D(), double mass = 1.0, double momentOfInertia = 1.0);

    // Getters
    Vector2D getPosition() const;
    Vector2D getVelocity() const;
    Vector2D getAcceleration() const;
    double getMass() const;
    double getAngle() const;
    double getAngularVelocity() const;
    double getAngularAcceleration() const;
    double getMomentOfInertia() const;
    Vector2D getForce() const;
    double getTorque() const;
    const std::vector<Vector2D>& getShape() const;
    bool getIsStatic() const;

    // Setters
    void setPosition(const Vector2D& pos);
    void setVelocity(const Vector2D& vel);
    void setAcceleration(const Vector2D& accel);
    void setMass(double mass);
    void setAngle(double angle);
    void setAngularVelocity(double angularVel);
    void setAngularAcceleration(double angularAccel);
    void setMomentOfInertia(double momentOfInertia);
    void setForce(const Vector2D& force);
    void setTorque(double torque);
    void setShape(const std::vector<Vector2D>& shape);
    void setIsStatic(bool isStatic);

    // Methods
    void applyForce(const Vector2D& force);
    void applyForceAtPoint(const Vector2D& force, const Vector2D& point);
    void applyTorque(double torque);
    void applyImpulse(const Vector2D& impulse);
    void applyAngularImpulse(double angularImpulse);
    void update(double deltaTime);
    Vector2D localToWorld(const Vector2D& localPoint) const;
    Vector2D worldToLocal(const Vector2D& worldPoint) const;

    // Utility methods
    double calculateMomentOfInertia() const; // For simple shapes
    void recenterShape();
};

#endif // RIGIDBODY2D_H