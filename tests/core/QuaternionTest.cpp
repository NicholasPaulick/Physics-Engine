#include <iostream>
#include <cassert>
#include <cmath>
#include "../include/core/Quaternion.h"

void testQuaternionAddition() {
    Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
    Quaternion q2(4.0f, 3.0f, 2.0f, 1.0f);
    Quaternion result = q1 + q2;
    assert(result.getW() == 5.0f && result.getX() == 5.0f && result.getY() == 5.0f && result.getZ() == 5.0f);
    std::cout << "testQuaternionAddion Passed!" << std::endl;
}

void testQuaternionSubtraction() {
    Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
    Quaternion q2(4.0f, 3.0f, 2.0f, 1.0f);
    Quaternion result = q1 - q2;
    assert(result.getW() == -3.0f && result.getX() == -1.0f && result.getY() == 1.0f && result.getZ() == 3.0f);
    std::cout << "testQuaternionSubtraction Passed!" << std::endl;
}

void testQuaternionMultiplication() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);
    Quaternion result = q1 * q2;

    assert(result.getW() == -60.0f && result.getX() == 12.0f &&
           result.getY() == 30.0f && result.getZ() == 24.0f);
    std::cout << "testQuaternionMultiplication Passed!" << std::endl;
}



void testQuaternionConjugate() {
    Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);
    Quaternion result = q.conjugate();
    assert(result.getW() == 1.0f && result.getX() == -2.0f && result.getY() == -3.0f && result.getZ() == -4.0f);
    std::cout << "testQuaternionConjugate Passed!" << std::endl;
}

void testQuaternionInverse() {
    Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);
    Quaternion inv = q.inverse();
    Quaternion expected = q.conjugate() * (1.0f / (q.norm() * q.norm()));
    for (int i = 0; i < 4; ++i) {
        assert(std::fabs(inv.getW() - expected.getW()) < 1e-5f);
        assert(std::fabs(inv.getX() - expected.getX()) < 1e-5f);
        assert(std::fabs(inv.getY() - expected.getY()) < 1e-5f);
        assert(std::fabs(inv.getZ() - expected.getZ()) < 1e-5f);
    }
    std::cout << "testQuaternionInverse Passed!" << std::endl;
}

int testQuaternion() {
    testQuaternionAddition();
    testQuaternionSubtraction();
    testQuaternionMultiplication();
    testQuaternionConjugate();
    testQuaternionInverse();
    std::cout << "Quaternion Tests finished\n" << std::endl;
    return 0;
}
