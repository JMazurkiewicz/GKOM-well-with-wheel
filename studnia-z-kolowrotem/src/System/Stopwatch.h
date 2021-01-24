#pragma once

#include <chrono>
#include <type_traits>

class Stopwatch {
public:
	using Clock = std::conditional_t<
		std::chrono::high_resolution_clock::is_steady,
		std::chrono::high_resolution_clock,
		std::chrono::steady_clock
	>;
	using TimePoint = Clock::time_point;

	using Duration = std::chrono::duration<float, std::milli>;

	Stopwatch();
	Stopwatch(const Stopwatch&) = delete;
	Stopwatch& operator=(const Stopwatch&) = delete;

	void reset();
	Duration getElapsedTime();

private:	
	TimePoint previous;
};