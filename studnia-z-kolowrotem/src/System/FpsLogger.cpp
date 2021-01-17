#include "FpsLogger.h"

#include <iostream>

namespace chrono = std::chrono;
using namespace std::chrono_literals;

FpsLogger::FpsLogger(const char* path) : file{path} {
	if(!file.is_open()) {
		std::cerr << "[fps:" << this << "] unable to open/create \"" << path << "\" file\n";
	}
	reset();
}

void FpsLogger::reset() {
	previousTime = Clock::now();
	frameCount = 0;
}

void FpsLogger::log() {
	TimePoint currentTime = Clock::now();
	++frameCount;
	if(currentTime - previousTime >= 1s) {
		file << frameCount << '\n'; /// @todo fix??
		reset();
	}
}
