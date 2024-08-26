#include <iostream>
#include <cassert>
#include "../include/physics/RigidBody2D.h"

void testRigidBody2D() {
    RigidBody2D body(Vector2D(0, 0), 2.0f);

    // Apply a force of (2, 3) for 1 second
    body.applyForce(Vector2D(2, 3));
    body.update(1.0f);
    assert(body.getPosition().getX() == 1.0f);
    assert(body.getPosition().getY() == 1.5f);
    body.update(1.0f);
    assert(body.getVelocity().getX() == 1.0f);
    assert(body.getVelocity().getY() == 1.5f);

    // Apply a torque of 2 for 1 second
    body.applyTorque(2.0f);
    body.update(1.0f);
    assert(body.getAngle() == 1.0f);
    assert(body.getAngularVelocity() == 1.0f);

    std::cout << "RigidBody2D Tests Finished\n" << std::endl;
}
