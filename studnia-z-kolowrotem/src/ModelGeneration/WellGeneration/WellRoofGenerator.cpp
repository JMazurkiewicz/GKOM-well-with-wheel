#include "WellRoofGenerator.h"

#include <cmath>
#include <glm/ext.hpp>

WellRoofGenerator::WellRoofGenerator(const WellModel& basicWellModel, const RoofModel& basicRoofModel)
	: basicWellModel{basicWellModel}, basicRoofModel{basicRoofModel}, randomNumberGenerator{std::random_device{}()},
	roofWidth{2.0f * basicWellModel.getInnerRadius()}, tileWidth{roofWidth / basicRoofModel.getTileCount()} { }

void WellRoofGenerator::prepareGenerators() {
	prepareDistribution();
	prepareLeftTileGenerators();
	prepareRightTileGenerators();
	prepareTransformations();
}

void WellRoofGenerator::prepareDistribution() {
	using Param = decltype(distribution)::param_type;
	const float minTileLength = basicRoofModel.getMinTileLength();
	const float maxTileLength = basicRoofModel.getMaxTileLength();
	distribution.param(Param{minTileLength, maxTileLength});
}

void WellRoofGenerator::prepareLeftTileGenerators() {
	leftTilesGenerators.resize(basicRoofModel.getTileCount());

	const auto rotation = glm::rotate(basicRoofModel.getAngle(), glm::vec3{1.0f, 0.0f, 0.0f});
	float xTranslation = (roofWidth - tileWidth) / 2.0f;
	
	for(CuboidGenerator& generator : leftTilesGenerators) {
		const float tileLength = distribution(randomNumberGenerator);

		generator.setHeight(basicRoofModel.getTileHeight());
		generator.setLength(tileLength);
		generator.setWidth(tileWidth);
		
		const auto translation = glm::translate(glm::vec3{xTranslation, 0.0f, tileLength / 2.0f});
		generator.setTransformation(rotation * translation);

		addGenerator(&generator);
		xTranslation -= tileWidth;
	}
}

void WellRoofGenerator::prepareRightTileGenerators() {
	rightTilesGenerators.resize(basicRoofModel.getTileCount());

	const auto rotation = glm::rotate(-basicRoofModel.getAngle(), glm::vec3{1.0f, 0.0f, 0.0f});
	float xTranslation = (roofWidth - tileWidth) / 2.0f;

	for(CuboidGenerator& generator : rightTilesGenerators) {
		const float tileLength = distribution(randomNumberGenerator);

		generator.setHeight(basicRoofModel.getTileHeight());
		generator.setLength(tileLength);
		generator.setWidth(tileWidth);

		const auto translation = glm::translate(glm::vec3{xTranslation, 0.0f, -(tileLength / 2.0f)});
		generator.setTransformation(rotation * translation);

		addGenerator(&generator);
		xTranslation -= tileWidth;
	}
}

void WellRoofGenerator::prepareTransformations() {
	const float yTranslation =
		basicWellModel.getHeight() +
		basicWellModel.getBracketHeight() +
		basicWellModel.getLogHeight() +
		(std::tan(basicRoofModel.getAngle()) * basicWellModel.getBracketRadius());

	const auto translation = glm::translate(glm::vec3{0.0f, yTranslation, 0.0f});
	setTransformation(translation);
}
