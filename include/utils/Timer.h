#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>

class Timer {
public:
    // Constructor and Destructor
    Timer();
    explicit Timer(const std::string& name, bool startImmediately = false);
    ~Timer();

    // Control methods
    void start();
    void stop();
    void reset();

    // Elapsed time getters
    double elapsedSeconds() const;
    double elapsedMilliseconds() const;
    double elapsedMicroseconds() const;
    double elapsedNanoseconds() const;

    // Utility method to print elapsed time
    void printElapsedTime() const;

private:
    std::string name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> startTime_;
    std::chrono::time_point<std::chrono::high_resolution_clock> endTime_;
    bool running_;
    bool hasResult_;
};

#endif // TIMER_H
