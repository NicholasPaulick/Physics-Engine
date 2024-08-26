#include "../include/utils/Timer.h"

Timer::Timer()
    : name_(""), running_(false), hasResult_(false) {}

Timer::Timer(const std::string& name, bool startImmediately)
    : name_(name), running_(false), hasResult_(false) {
    if (startImmediately) {
        start();
    }
}

Timer::~Timer() {
    if (running_) {
        stop();
    }
    if (!name_.empty() && hasResult_) {
        printElapsedTime();
    }
}

void Timer::start() {
    if (!running_) {
        startTime_ = std::chrono::high_resolution_clock::now();
        running_ = true;
        hasResult_ = false;
    }
}

void Timer::stop() {
    if (running_) {
        endTime_ = std::chrono::high_resolution_clock::now();
        running_ = false;
        hasResult_ = true;
    }
}

void Timer::reset() {
    running_ = false;
    hasResult_ = false;
}

double Timer::elapsedSeconds() const {
    if (running_) {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double>(now - startTime_).count();
    } else if (hasResult_) {
        return std::chrono::duration<double>(endTime_ - startTime_).count();
    }
    return 0.0;
}

double Timer::elapsedMilliseconds() const {
    return elapsedSeconds() * 1000.0;
}

double Timer::elapsedMicroseconds() const {
    return elapsedSeconds() * 1'000'000.0;
}

double Timer::elapsedNanoseconds() const {
    return elapsedSeconds() * 1'000'000'000.0;
}

void Timer::printElapsedTime() const {
    std::cout << "Timer [" << name_ << "] elapsed time: "
              << elapsedMilliseconds() << " ms" << std::endl;
}
