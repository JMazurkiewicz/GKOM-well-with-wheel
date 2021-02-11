#pragma once

#include "../BasicGenerators/CuboidGenerator.h"
#include "../BasicGenerators/CompoundModelGenerator.h"
#include "Model/RoofModel.h"
#include "Model/WellModel.h"

#include <random>

class WellRoofGenerator final : public CompoundModelGenerator {
public:
	explicit WellRoofGenerator(const WellModel& basicWellModel, const RoofModel& basicRoofModel);

	void setSeed(unsigned newSeed);

private:
	void prepareGenerators() override;
	void prepareDistribution();
	
	void prepareLeftTileGenerators();
	void prepareRightTileGenerators();
	void prepareTileGenerators(std::vector<CuboidGenerator>& tilesGenerators, int sign);

	void prepareTransformations();

	const WellModel& basicWellModel;
	const RoofModel& basicRoofModel;

	const float roofWidth;
	const float tileWidth;

	std::mt19937 randomGenerator;
	std::uniform_real_distribution<float> distribution;

	std::vector<CuboidGenerator> leftTilesGenerators;
	std::vector<CuboidGenerator> rightTilesGenerators;
};
