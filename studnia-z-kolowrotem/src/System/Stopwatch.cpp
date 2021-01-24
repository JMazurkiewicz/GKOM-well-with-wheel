#include "Stopwatch.h"

namespace chrono = std::chrono;

constexpr Stopwatch::Stopwatch() {
}

void Stopwatch::reset() {
    previous = Clock::now();
}

Stopwatch::Milliseconds Stopwatch::getElapsedMilliseconds() {
    return std::chrono::duration_cast<Milliseconds>(getElapsedTime());
}

Stopwatch::Seconds Stopwatch::getElapsedSeconds() {
    return std::chrono::duration_cast<Seconds>(getElapsedTime());
}

Stopwatch::Clock::duration Stopwatch::getElapsedTime() {
    const TimePoint now = Clock::now();
    const Clock::duration time = now - previous;
    reset();
    return time;
}
