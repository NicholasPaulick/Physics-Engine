#include "../include/physics/RigidBody2D.h"

RigidBody2D::RigidBody2D(const Vector2D& position, float mass)
    : position(position), velocity(0, 0), acceleration(0, 0), mass(mass), angle(0), angularVelocity(0), torque(0) {}

Vector2D RigidBody2D::getPosition() const { return position; }
Vector2D RigidBody2D::getVelocity() const { return velocity; }
Vector2D RigidBody2D::getAcceleration() const { return acceleration; }
float RigidBody2D::getMass() const { return mass; }
float RigidBody2D::getAngle() const { return angle; }
float RigidBody2D::getAngularVelocity() const { return angularVelocity; }

void RigidBody2D::setPosition(const Vector2D& pos) { position = pos; }
void RigidBody2D::setVelocity(const Vector2D& vel) { velocity = vel; }
void RigidBody2D::setAcceleration(const Vector2D& accel) { acceleration = accel; }
void RigidBody2D::setMass(float mass) { this->mass = mass; }
void RigidBody2D::setAngle(float angle) { this->angle = angle; }
void RigidBody2D::setAngularVelocity(float angularVel) { angularVelocity = angularVel; }

void RigidBody2D::applyForce(const Vector2D& force) {
    acceleration = acceleration + (force / mass);
}

void RigidBody2D::applyTorque(float torque) {
    this->torque += torque;
}

void RigidBody2D::update(float deltaTime) {
    velocity = velocity + (acceleration * deltaTime);
    position = position + (velocity * deltaTime);
    angularVelocity += (torque / mass) * deltaTime;
    angle += angularVelocity * deltaTime;

    // Reset acceleration
    acceleration = Vector2D(0, 0);
}
