#pragma once

#include "../BasicGenerators/CompoundModelGenerator.h"
#include "../BasicGenerators/HollowCylinderGenerator.h"
#include "Model/WellModel.h"

class WellBaseGenerator final : public CompoundModelGenerator {
public:
    static constexpr unsigned DEFAULT_SAMPLE_RATE = 32;

    WellBaseGenerator(const WellModel& basicModel);
    void setSampleRate(unsigned newSampleRate);

private:
    void prepareGenerators() override;

    const WellModel& basicModel;
    unsigned sampleRate;

    HollowCylinderGenerator baseGenerator;
};
