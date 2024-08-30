#include "../include/physics/RigidBody2D.h"
#include <numeric>
#include <algorithm>

RigidBody2D::RigidBody2D(const Vector2D& position, double mass, double momentOfInertia)
    : position(position), velocity(0, 0), acceleration(0, 0), mass(mass),
      angle(0), angularVelocity(0), angularAcceleration(0),
      momentOfInertia(momentOfInertia), force(0, 0), torque(0), isStatic(false) {}

// Getters
Vector2D RigidBody2D::getPosition() const { return position; }
Vector2D RigidBody2D::getVelocity() const { return velocity; }
Vector2D RigidBody2D::getAcceleration() const { return acceleration; }
double RigidBody2D::getMass() const { return mass; }
double RigidBody2D::getAngle() const { return angle; }
double RigidBody2D::getAngularVelocity() const { return angularVelocity; }
double RigidBody2D::getAngularAcceleration() const { return angularAcceleration; }
double RigidBody2D::getMomentOfInertia() const { return momentOfInertia; }
Vector2D RigidBody2D::getForce() const { return force; }
double RigidBody2D::getTorque() const { return torque; }
const std::vector<Vector2D>& RigidBody2D::getShape() const { return shape; }
bool RigidBody2D::getIsStatic() const { return isStatic; }

// Setters
void RigidBody2D::setPosition(const Vector2D& pos) { position = pos; }
void RigidBody2D::setVelocity(const Vector2D& vel) { velocity = vel; }
void RigidBody2D::setAcceleration(const Vector2D& accel) { acceleration = accel; }
void RigidBody2D::setMass(double mass) { this->mass = mass; }
void RigidBody2D::setAngle(double angle) { this->angle = angle; }
void RigidBody2D::setAngularVelocity(double angularVel) { angularVelocity = angularVel; }
void RigidBody2D::setAngularAcceleration(double angularAccel) { angularAcceleration = angularAccel; }
void RigidBody2D::setMomentOfInertia(double momentOfInertia) { this->momentOfInertia = momentOfInertia; }
void RigidBody2D::setForce(const Vector2D& force) { this->force = force; }
void RigidBody2D::setTorque(double torque) { this->torque = torque; }
void RigidBody2D::setShape(const std::vector<Vector2D>& shape) { this->shape = shape; }
void RigidBody2D::setIsStatic(bool isStatic) { this->isStatic = isStatic; }

void RigidBody2D::applyForce(const Vector2D& force) {
    this->force += force;
}

void RigidBody2D::applyForceAtPoint(const Vector2D& force, const Vector2D& point) {
    this->force += force;
    Vector2D r = point - position;
    torque += r.cross(force);
}

void RigidBody2D::applyTorque(double torque) {
    this->torque += torque;
}

void RigidBody2D::applyImpulse(const Vector2D& impulse) {
    velocity += impulse / mass;
}

void RigidBody2D::applyAngularImpulse(double angularImpulse) {
    angularVelocity += angularImpulse / momentOfInertia;
}

void RigidBody2D::update(double deltaTime) {
    if (isStatic) return;

    // Update linear motion
    acceleration = force / mass;
    velocity += acceleration * deltaTime;
    position += velocity * deltaTime;

    // Update angular motion
    angularAcceleration = torque / momentOfInertia;
    angularVelocity += angularAcceleration * deltaTime;
    angle += angularVelocity * deltaTime;

    // Reset force and torque
    force = Vector2D(0, 0);
    torque = 0;
}

Vector2D RigidBody2D::localToWorld(const Vector2D& localPoint) const {
    Matrix2x2 rotationMatrix = Matrix2x2::rotation(angle);
    return position + rotationMatrix * localPoint;
}

Vector2D RigidBody2D::worldToLocal(const Vector2D& worldPoint) const {
    Matrix2x2 inverseRotationMatrix = Matrix2x2::rotation(-angle);
    return inverseRotationMatrix * (worldPoint - position);
}

double RigidBody2D::calculateMomentOfInertia() const {
    // Simple calculation for a polygon shape
    if (shape.size() < 3) return momentOfInertia; // Return current value if shape is not defined

    double area = 0.0;
    double moment = 0.0;
    for (size_t i = 0; i < shape.size(); ++i) {
        const Vector2D& p1 = shape[i];
        const Vector2D& p2 = shape[(i + 1) % shape.size()];
        double cross = p1.cross(p2);
        area += cross;
        moment += (p1.dot(p1) + p2.dot(p2) + p1.dot(p2)) * cross;
    }
    area /= 2.0;
    return mass * moment / (6.0 * area);
}

void RigidBody2D::recenterShape() {
    if (shape.empty()) return;

    Vector2D centroid(0, 0);
    for (const auto& point : shape) {
        centroid += point;
    }
    centroid /= static_cast<double>(shape.size());

    for (auto& point : shape) {
        point -= centroid;
    }
    position += centroid;
}