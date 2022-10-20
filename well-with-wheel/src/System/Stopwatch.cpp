#include "Stopwatch.h"

Stopwatch::Stopwatch() {
    reset();
}

void Stopwatch::reset() {
    previous = Clock::now();
}

Stopwatch::Duration Stopwatch::getElapsedTime() {
    const TimePoint now = Clock::now();
    const Clock::duration time = now - previous;
    reset();
    return std::chrono::duration_cast<Duration>(time);
}
