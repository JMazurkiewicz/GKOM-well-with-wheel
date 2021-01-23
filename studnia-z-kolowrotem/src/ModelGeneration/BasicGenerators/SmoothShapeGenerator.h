#pragma once

#include "PrimitiveGenerator.h"

class SmoothShapeGenerator : public PrimitiveGenerator {
public:
	static constexpr unsigned DEFAULT_SAMPLE_RATE = 64;

	SmoothShapeGenerator();
	using PrimitiveGenerator::PrimitiveGenerator;

	void setSampleRate(unsigned newSampleRate);

protected:
	unsigned getSampleRate() const;

private:
	unsigned sampleRate;
};