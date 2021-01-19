#include "SmoothShapeGenerator.h"

SmoothShapeGenerator::SmoothShapeGenerator()
    : ModelGenerator(), sampleRate{DEFAULT_SAMPLE_RATE} { }

void SmoothShapeGenerator::setSampleRate(unsigned newSampleRate) {
    sampleRate = newSampleRate;
}

unsigned SmoothShapeGenerator::getSampleRate() const {
    return sampleRate;
}
