#pragma once

#include "../BasicGenerators/ClosedCylinderGenerator.h"
#include "../BasicGenerators/CompoundModelGenerator.h"
#include "../BasicGenerators/CuboidGenerator.h"
#include "../BasicGenerators/HollowCylinderGenerator.h"
#include "Model/WellModel.h"
#include "Model/WheelModel.h"

#include <vector>

class WheelGenerator final : public CompoundModelGenerator {
public:
    static constexpr unsigned DEFAULT_SAMPLE_RATE = 24;

    explicit WheelGenerator(const WellModel& basicWellModel, const WheelModel& basicModel);
    void setSampleRate(unsigned newSampleRate);

private:
    void prepareGenerators() override;

    void prepareMiddleElementGenerator();
    void prepareRingGenerator();
    void prepareHoldingCylinderGenerator();
    void prepareCuboidGenerators();
    void prepareTransformation();

    const WellModel& basicWellModel;
    const WheelModel& basicWheelModel;
    unsigned sampleRate;

    ClosedCylinderGenerator middleElementGenerator;
    HollowCylinderGenerator ringGenerator;
    std::vector<CuboidGenerator> cuboidGenerators;
    CylinderGenerator holdingCylinderGenerator;
};
