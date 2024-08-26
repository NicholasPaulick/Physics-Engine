#include <iostream>
#include <cassert>
#include "../include/physics/Friction2D.h"

void testFriction2D() {
    RigidBody2D body(Vector2D(0, 0), 2.0f);
    Friction2D friction;
    body.applyForce(Vector2D(1, 1));
    body.update(1.0f);
    Vector2D frictionC = friction.calculateFriction(body, 0.5, 5);

    assert(frictionC.getX() == -5.0f);
    assert(frictionC.getY() == 0.0f);

    std::cout << "Friction2D Tests Finished\n" << std::endl;
}
