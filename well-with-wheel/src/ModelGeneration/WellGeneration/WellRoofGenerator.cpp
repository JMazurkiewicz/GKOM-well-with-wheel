#include "WellRoofGenerator.h"

#include <cmath>

#include <glm/ext.hpp>

WellRoofGenerator::WellRoofGenerator(const WellModel& basicWellModel, const RoofModel& basicRoofModel)
    : basicWellModel{basicWellModel}
    , basicRoofModel{basicRoofModel}
    , roofWidth{2.0f * basicWellModel.getInnerRadius()}
    , tileWidth{roofWidth / basicRoofModel.getTileCount()} { }

void WellRoofGenerator::setSeed(unsigned newSeed) {
    randomGenerator.seed(newSeed);
}

void WellRoofGenerator::prepareGenerators() {
    prepareDistribution();
    prepareLeftTileGenerators();
    prepareRightTileGenerators();
    prepareTransformations();
}

void WellRoofGenerator::prepareDistribution() {
    const float minTileLength = basicRoofModel.getMinTileLength();
    const float maxTileLength = basicRoofModel.getMaxTileLength();

    using Param = decltype(distribution)::param_type;
    distribution.param(Param{minTileLength, maxTileLength});
}

void WellRoofGenerator::prepareLeftTileGenerators() {
    prepareTileGenerators(leftTilesGenerators, 1);
}

void WellRoofGenerator::prepareRightTileGenerators() {
    prepareTileGenerators(rightTilesGenerators, -1);
}

void WellRoofGenerator::prepareTileGenerators(std::vector<CuboidGenerator>& tilesGenerators, int sign) {
    tilesGenerators.resize(basicRoofModel.getTileCount());

    const auto rotation = glm::rotate(sign * basicRoofModel.getAngle(), glm::vec3{1.0f, 0.0f, 0.0f});
    float xTranslation = (roofWidth - tileWidth) / 2.0f;

    for(CuboidGenerator& generator : tilesGenerators) {
        const float tileLength = distribution(randomGenerator);

        generator.setLength(tileLength);
        generator.setHeight(basicRoofModel.getTileHeight());
        generator.setWidth(tileWidth);

        const float zTranslation = sign * (tileLength / 2.0f);
        const auto translation = glm::translate(glm::vec3{xTranslation, 0.0f, zTranslation});

        generator.setTransformation(rotation * translation);

        addGenerator(generator);
        xTranslation -= tileWidth;
    }
}

void WellRoofGenerator::prepareTransformations() {
    const float yTranslation = basicWellModel.getHeight() + basicWellModel.getBracketHeight() +
                               basicWellModel.getLogHeight() +
                               (std::tan(basicRoofModel.getAngle()) * basicWellModel.getBracketRadius());

    const auto translation = glm::translate(glm::vec3{0.0f, yTranslation, 0.0f});
    setTransformation(translation);
}
