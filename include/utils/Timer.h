#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <iostream>
#include <vector>

class Timer {
public:
    // Constructors and Destructor
    Timer();
    explicit Timer(const std::string& name, bool startImmediately = false);
    ~Timer();

    // Control methods
    void start();
    void stop();
    void reset();
    void lap();

    // Elapsed time getters
    double elapsedSeconds() const;
    double elapsedMilliseconds() const;
    double elapsedMicroseconds() const;
    double elapsedNanoseconds() const;

    // Lap time getters
    std::vector<double> getLapTimes() const;

    // Utility methods
    void printElapsedTime() const;
    void printLapTimes() const;

    // Getter for name
    std::string getName() const;

private:
    std::string name_;
    std::chrono::time_point<std::chrono::steady_clock> startTime_;
    std::chrono::time_point<std::chrono::steady_clock> endTime_;
    std::vector<std::chrono::time_point<std::chrono::steady_clock>> lapTimes_;
    bool running_;
    bool hasResult_;

    double calculateDuration(std::chrono::time_point<std::chrono::steady_clock> start,
                             std::chrono::time_point<std::chrono::steady_clock> end) const;
};

#endif // TIMER_H