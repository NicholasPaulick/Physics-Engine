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
        startTime_ = std::chrono::steady_clock::now();
        running_ = true;
        hasResult_ = false;
        lapTimes_.clear();
    }
}

void Timer::stop() {
    if (running_) {
        endTime_ = std::chrono::steady_clock::now();
        running_ = false;
        hasResult_ = true;
    }
}

void Timer::reset() {
    running_ = false;
    hasResult_ = false;
    lapTimes_.clear();
}

void Timer::lap() {
    if (running_) {
        lapTimes_.push_back(std::chrono::steady_clock::now());
    }
}

double Timer::calculateDuration(std::chrono::time_point<std::chrono::steady_clock> start,
                                std::chrono::time_point<std::chrono::steady_clock> end) const {
    return std::chrono::duration<double>(end - start).count();
}

double Timer::elapsedSeconds() const {
    if (running_) {
        auto now = std::chrono::steady_clock::now();
        return calculateDuration(startTime_, now);
    } else if (hasResult_) {
        return calculateDuration(startTime_, endTime_);
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

std::vector<double> Timer::getLapTimes() const {
    std::vector<double> times;
    if (!lapTimes_.empty()) {
        times.reserve(lapTimes_.size());
        auto prevTime = startTime_;
        for (const auto& lapTime : lapTimes_) {
            times.push_back(calculateDuration(prevTime, lapTime));
            prevTime = lapTime;
        }
    }
    return times;
}

void Timer::printElapsedTime() const {
    std::cout << "Timer [" << name_ << "] elapsed time: "
              << elapsedMilliseconds() << " ms" << std::endl;
}

void Timer::printLapTimes() const {
    auto times = getLapTimes();
    if (!times.empty()) {
        std::cout << "Timer [" << name_ << "] lap times:" << std::endl;
        for (size_t i = 0; i < times.size(); ++i) {
            std::cout << "  Lap " << (i + 1) << ": " << (times[i] * 1000.0) << " ms" << std::endl;
        }
    }
}

std::string Timer::getName() const {
    return name_;
}