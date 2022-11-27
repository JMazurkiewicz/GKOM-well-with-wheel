#include "SmoothShapeGenerator.h"

void SmoothShapeGenerator::setSampleRate(unsigned newSampleRate) {
    sampleRate = newSampleRate;
}

unsigned SmoothShapeGenerator::getSampleRate() const noexcept {
    return sampleRate;
}
