#pragma once

#include <chrono>
#include <fstream>

class FpsLogger {
public:
	using Clock = std::chrono::high_resolution_clock;
	using TimePoint = Clock::time_point;

	explicit FpsLogger(const char* path);
	FpsLogger(const FpsLogger&) = delete;
	FpsLogger& operator=(const FpsLogger&) = delete;

	void reset();
	void log();

private:
	std::ofstream file;
	TimePoint previousTime;
	unsigned frameCount;
};