#pragma once

#include <chrono>

class Stopwatch {
public:
    using Clock = std::chrono::steady_clock;
    using TimePoint = Clock::time_point;
    using Duration = std::chrono::duration<float>;

    Stopwatch();
    Stopwatch(const Stopwatch&) = delete;
    Stopwatch& operator=(const Stopwatch&) = delete;

    void reset();
    Duration getElapsedTime();

private:
    TimePoint previous;
};
