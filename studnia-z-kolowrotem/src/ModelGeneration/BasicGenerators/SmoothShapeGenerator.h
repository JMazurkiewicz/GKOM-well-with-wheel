#pragma once

#include "PrimitiveGenerator.h"

class SmoothShapeGenerator : public PrimitiveGenerator {
public:
	static constexpr unsigned DEFAULT_SAMPLE_RATE = 64;

	SmoothShapeGenerator();
	SmoothShapeGenerator(const SmoothShapeGenerator&) = delete;
	SmoothShapeGenerator& operator=(const SmoothShapeGenerator&) = delete;

	void setSampleRate(unsigned newSampleRate);

protected:
	unsigned getSampleRate() const;

private:
	unsigned sampleRate;
};