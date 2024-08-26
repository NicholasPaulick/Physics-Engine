#include <iostream>
#include <thread>
#include <cassert>
#include "../include/utils/Timer.h"

void testTimerBasicFunctionality() {
    Timer timer;
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    timer.stop();

    double elapsed = timer.elapsedMilliseconds();
    std::cout << "Elapsed Time: " << elapsed << " ms" << std::endl;

    assert(elapsed >= 100.0 && elapsed < 200.0);
    std::cout << "testTimerBasicFunctionality passed." << std::endl;
}

void testTimerScopedTiming() {
    {
        Timer timer("Scoped Timer", true);
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
    std::cout << "testTimerScopedTiming passed." << std::endl;
}

void testTimerReset() {
    Timer timer;
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    timer.stop();

    double firstElapsed = timer.elapsedMilliseconds();
    assert(firstElapsed >= 30.0 && firstElapsed < 100.0);

    timer.reset();
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(60));
    timer.stop();

    double secondElapsed = timer.elapsedMilliseconds();
    assert(secondElapsed >= 60.0 && secondElapsed < 120.0);

    std::cout << "testTimerReset passed." << std::endl;
}

void testTimerContinuousRunning() {
    Timer timer;
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(20));

    double interimElapsed = timer.elapsedMilliseconds();
    assert(interimElapsed >= 20.0 && interimElapsed < 100.0);

    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    timer.stop();

    double totalElapsed = timer.elapsedMilliseconds();
    assert(totalElapsed >= 50.0 && totalElapsed < 150.0);

    std::cout << "testTimerContinuousRunning passed." << std::endl;
}

int testTimer() {
    testTimerBasicFunctionality();
    testTimerScopedTiming();
    testTimerReset();
    testTimerContinuousRunning();

    std::cout << "Timer tests completed\n" << std::endl;
    return 0;
}
