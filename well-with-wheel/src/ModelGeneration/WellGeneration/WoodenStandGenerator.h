#pragma once

#include "../BasicGenerators/CompoundModelGenerator.h"
#include "../BasicGenerators/CuboidGenerator.h"
#include "../BasicGenerators/CylinderGenerator.h"
#include "Model/WellModel.h"

class WoodenStandGenerator final : public CompoundModelGenerator {
public:
    static constexpr unsigned DEFAULT_SAMPLE_RATE = 32;

    explicit WoodenStandGenerator(const WellModel& basicModel);

    void setSampleRate(unsigned newSampleRate);

private:
    void prepareGenerators() override;
    void prepareLeftBracketGenerator();
    void prepareRightBracketGenerator();
    void prepareLogGenerator();

    const WellModel& basicModel;
    unsigned sampleRate;

    CylinderGenerator leftBracketGenerator;
    CylinderGenerator rightBracketGenerator;
    CuboidGenerator logGenerator;
};
