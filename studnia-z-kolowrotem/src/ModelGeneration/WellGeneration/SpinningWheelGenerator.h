#pragma once

#include "../BasicGenerators/ClosedCylinderGenerator.h"
#include "../BasicGenerators/CompoundModelGenerator.h"
#include "../BasicGenerators/CuboidGenerator.h"
#include "../BasicGenerators/HollowCylinderGenerator.h"
#include "Model/WheelModel.h"
#include <vector>

class SpinningWheelGenerator final : public CompoundModelGenerator {
public:
	static constexpr unsigned DEFAULT_SAMPLE_RATE = 24;

	SpinningWheelGenerator(const WheelModel& basicModel);
	void setSampleRate(unsigned newSampleRate);

private:
	void prepareGenerators() override;
	void prepareMiddleElementGenerator();
	void prepareRingGenerator();
	void prepareCuboidGenerators();

	const WheelModel& basicModel;
	unsigned sampleRate;

	ClosedCylinderGenerator middleElementGenerator;
	HollowCylinderGenerator ringGenerator;
	std::vector<CuboidGenerator> cuboidGenerators;
};