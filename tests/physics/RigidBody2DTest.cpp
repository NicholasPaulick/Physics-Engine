#include <iostream>
#include <cassert>
#include <cmath>
#include "../include/physics/RigidBody2D.h"

const double EPSILON = 1e-6;

bool approxEq(double a, double b) {
    return std::abs(a - b) < EPSILON;
}

void testConstructor() {
    RigidBody2D body(Vector2D(1, 2), 3.0, 4.0);
    assert(approxEq(body.getPosition().getX(), 1.0));
    assert(approxEq(body.getPosition().getY(), 2.0));
    assert(approxEq(body.getMass(), 3.0));
    assert(approxEq(body.getMomentOfInertia(), 4.0));
    assert(approxEq(body.getVelocity().getX(), 0.0));
    assert(approxEq(body.getVelocity().getY(), 0.0));
    assert(approxEq(body.getAcceleration().getX(), 0.0));
    assert(approxEq(body.getAcceleration().getY(), 0.0));
    std::cout << "Constructor test passed" << std::endl;
}

void testApplyForce() {
    RigidBody2D body(Vector2D(0, 0), 2.0);
    body.applyForce(Vector2D(2, 3));
    body.update(1.0);
    assert(approxEq(body.getPosition().getX(), 1.0));
    assert(approxEq(body.getPosition().getY(), 1.5));
    assert(approxEq(body.getVelocity().getX(), 1.0));
    assert(approxEq(body.getVelocity().getY(), 1.5));
    assert(approxEq(body.getAcceleration().getX(), 1.0));
    assert(approxEq(body.getAcceleration().getY(), 1.5));
    std::cout << "Apply force test passed" << std::endl;
}

void testApplyTorque() {
    RigidBody2D body(Vector2D(0, 0), 2.0, 1.0);
    body.applyTorque(2.0);
    body.update(1.0);
    assert(approxEq(body.getAngularAcceleration(), 2.0));
    assert(approxEq(body.getAngularVelocity(), 2.0));
    assert(approxEq(body.getAngle(), 2.0));

    std::cout << "Apply torque test passed" << std::endl;
}


void testApplyForceAtPoint() {
    RigidBody2D body(Vector2D(0, 0), 2.0, 1.0);
    body.applyForceAtPoint(Vector2D(0, 1), Vector2D(1, 0));
    body.update(1.0);
    assert(approxEq(body.getPosition().getY(), 0.5));
    assert(approxEq(body.getVelocity().getY(), 0.5));
    assert(approxEq(body.getAngle(), 1));
    assert(approxEq(body.getAngularVelocity(), 1.0));
    std::cout << "Apply force at point test passed" << std::endl;
}

void testApplyImpulse() {
    RigidBody2D body(Vector2D(0, 0), 2.0);
    body.applyImpulse(Vector2D(2, 3));
    assert(approxEq(body.getVelocity().getX(), 1.0));
    assert(approxEq(body.getVelocity().getY(), 1.5));
    std::cout << "Apply impulse test passed" << std::endl;
}

void testApplyAngularImpulse() {
    RigidBody2D body(Vector2D(0, 0), 2.0, 1.0);
    body.applyAngularImpulse(2.0);
    assert(approxEq(body.getAngularVelocity(), 2.0));
    std::cout << "Apply angular impulse test passed" << std::endl;
}

void testLocalToWorld() {
    RigidBody2D body(Vector2D(1, 1), 2.0, 1.0);
    body.setAngle(M_PI / 4); // 45 degrees
    Vector2D localPoint(1, 0);
    Vector2D worldPoint = body.localToWorld(localPoint);
    assert(approxEq(worldPoint.getX(), 1 + std::sqrt(2) / 2));
    assert(approxEq(worldPoint.getY(), 1 + std::sqrt(2) / 2));
    std::cout << "Local to world transformation test passed" << std::endl;
}

void testWorldToLocal() {
    RigidBody2D body(Vector2D(1, 1), 2.0, 1.0);
    body.setAngle(M_PI / 4); // 45 degrees
    Vector2D worldPoint(2, 2);
    Vector2D localPoint = body.worldToLocal(worldPoint);
    assert(approxEq(localPoint.getX(), std::sqrt(2)));
    assert(approxEq(localPoint.getY(), 0));
    std::cout << "World to local transformation test passed" << std::endl;
}

void testStaticBody() {
    RigidBody2D body(Vector2D(0, 0), 2.0);
    body.setIsStatic(true);
    body.applyForce(Vector2D(2, 3));
    body.applyTorque(2.0);
    body.update(1.0);
    assert(approxEq(body.getPosition().getX(), 0));
    assert(approxEq(body.getPosition().getY(), 0));
    assert(approxEq(body.getVelocity().getX(), 0));
    assert(approxEq(body.getVelocity().getY(), 0));
    assert(approxEq(body.getAngle(), 0));
    assert(approxEq(body.getAngularVelocity(), 0));
    std::cout << "Static body test passed" << std::endl;
}

void testMomentOfInertia() {
    RigidBody2D body(Vector2D(0, 0), 1.0);
    std::vector<Vector2D> shape = {
        Vector2D(-1, -1),
        Vector2D(1, -1),
        Vector2D(1, 1),
        Vector2D(-1, 1)
    };
    body.setShape(shape);
    double calculatedMoI = body.calculateMomentOfInertia();
    assert(approxEq(calculatedMoI, 4.0 / 3.0)); // For a unit square with mass 1
    std::cout << "Moment of inertia calculation test passed" << std::endl;
}

void testRigidBody2D() {
    testConstructor();
    testApplyForce();
    testApplyTorque();
    testApplyForceAtPoint();
    testApplyImpulse();
    testApplyAngularImpulse();
    testLocalToWorld();
    testWorldToLocal();
    testStaticBody();
    testMomentOfInertia();
    std::cout << "RigidBody2D tests finished\n" << std::endl;
}
