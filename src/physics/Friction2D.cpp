// Friction2D.cpp
#include "../include/physics/Friction2D.h"

Vector2D Friction2D::calculateFriction(const RigidBody2D& body, float coefficientOfFriction, float gravity) {
    Vector2D frictionForce = -body.getMass() * coefficientOfFriction * gravity;
    return frictionForce;
}