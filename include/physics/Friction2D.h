// Friction2D.h
#pragma once
#include "RigidBody2D.h"

class Friction2D {
public:
    static Vector2D calculateFriction(const RigidBody2D& body, float coefficientOfFriction, float gravity);
};

