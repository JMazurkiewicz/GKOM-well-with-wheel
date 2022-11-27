#pragma once

#include "PrimitiveGenerator.h"

class SmoothShapeGenerator : public PrimitiveGenerator {
public:
    static constexpr unsigned DEFAULT_SAMPLE_RATE = 32;

    SmoothShapeGenerator() = default;
    using PrimitiveGenerator::PrimitiveGenerator;

    void setSampleRate(unsigned newSampleRate);

protected:
    [[nodiscard]] unsigned getSampleRate() const noexcept;

private:
    unsigned sampleRate = DEFAULT_SAMPLE_RATE;
};
