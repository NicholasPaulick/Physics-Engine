#ifndef RIGIDBODY2D_H
#define RIGIDBODY2D_H

#include "../include/core/Vector2D.h"

class RigidBody2D {
private:
    Vector2D position;
    Vector2D velocity;
    Vector2D acceleration;
    float mass;
    float angle;
    float angularVelocity;
    float torque;

public:
    RigidBody2D(const Vector2D& position = Vector2D(), float mass = 1.0f);

    // Getters
    Vector2D getPosition() const;
    Vector2D getVelocity() const;
    Vector2D getAcceleration() const;
    float getMass() const;
    float getAngle() const;
    float getAngularVelocity() const;

    // Setters
    void setPosition(const Vector2D& pos);
    void setVelocity(const Vector2D& vel);
    void setAcceleration(const Vector2D& accel);
    void setMass(float mass);
    void setAngle(float angle);
    void setAngularVelocity(float angularVel);

    // Methods
    void applyForce(const Vector2D& force);
    void applyTorque(float torque);
    void update(float deltaTime);
};

#endif
