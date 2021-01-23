#pragma once

#include "../BasicGenerators/CuboidGenerator.h"
#include "../BasicGenerators/CompoundModelGenerator.h"
#include "Model/RoofModel.h"
#include "Model/WellModel.h"
#include <random>

class WellRoofGenerator : public CompoundModelGenerator {
public:
	explicit WellRoofGenerator(const WellModel& basicWellModel, const RoofModel& basicRoofModel);

private:
	void prepareGenerators() override;
	void prepareDistribution();
	void prepareLeftTileGenerators();
	void prepareRightTileGenerators();
	void prepareTransformations();

	const WellModel& basicWellModel;
	const RoofModel& basicRoofModel;

	const float roofWidth;
	const float tileWidth;

	std::mt19937 randomNumberGenerator;
	std::uniform_real_distribution<float> distribution;

	std::vector<CuboidGenerator> leftTilesGenerators;
	std::vector<CuboidGenerator> rightTilesGenerators;
};
