#include "WheelGenerator.h"

#include <numbers>

#include <glm/ext.hpp>

using namespace std::numbers;

WheelGenerator::WheelGenerator(const WellModel& basicWellModel, const WheelModel& basicModel)
    : basicWellModel{basicWellModel}
    , basicWheelModel{basicModel}
    , sampleRate{DEFAULT_SAMPLE_RATE} { }

void WheelGenerator::setSampleRate(unsigned newSampleRate) {
    sampleRate = newSampleRate;
}

void WheelGenerator::prepareGenerators() {
    prepareMiddleElementGenerator();
    prepareRingGenerator();
    prepareCuboidGenerators();
    prepareHoldingCylinderGenerator();
    prepareTransformation();
}

void WheelGenerator::prepareMiddleElementGenerator() {
    middleElementGenerator.setSampleRate(sampleRate);
    middleElementGenerator.setHeight(basicWheelModel.getHeight());
    middleElementGenerator.setRadius(basicWheelModel.getMiddleElementRadius());
    addGenerator(middleElementGenerator);
}

void WheelGenerator::prepareRingGenerator() {
    ringGenerator.setSampleRate(sampleRate);
    ringGenerator.setHeight(basicWheelModel.getHeight());
    ringGenerator.setInnerRadius(basicWheelModel.getInnerRadius());
    ringGenerator.setOuterRadius(basicWheelModel.getOuterRadius());
    addGenerator(ringGenerator);
}

void WheelGenerator::prepareHoldingCylinderGenerator() {
    holdingCylinderGenerator.setSampleRate(sampleRate);
    holdingCylinderGenerator.setRadius(basicWheelModel.getMiddleElementRadius());

    const float height = 2.0f * (basicWellModel.getInnerRadius() - basicWellModel.getBracketRadius());
    holdingCylinderGenerator.setHeight(height);

    const glm::vec3 yTranslation = {0.0f, -height, 0.0f};
    holdingCylinderGenerator.setTransformation(glm::translate(yTranslation));

    addGenerator(holdingCylinderGenerator);
}

void WheelGenerator::prepareCuboidGenerators() {
    cuboidGenerators.resize(basicWheelModel.getConnectorCount());

    const glm::vec3 commonTranslation = {basicWheelModel.getInnerRadius() / 2.0f,
                                         (basicWheelModel.getHeight() - basicWheelModel.getConnectorHeight()) / 2.0f,
                                         0.0f};

    const float angleChange = 2.0f * pi_v<float> / basicWheelModel.getConnectorCount();

    for(float angle = 0.0f; CuboidGenerator & generator : cuboidGenerators) {
        generator.setHeight(basicWheelModel.getConnectorHeight());
        generator.setLength(basicWheelModel.getMiddleElementRadius());
        generator.setWidth(basicWheelModel.getInnerRadius());

        const auto translation = glm::translate(glm::rotateY(commonTranslation, -angle));
        const auto rotation = glm::rotate(-angle, glm::vec3{0.0f, 1.0f, 0.0f});
        generator.setTransformation(translation * rotation);

        addGenerator(generator);
        angle += angleChange;
    }
}

void WheelGenerator::prepareTransformation() {
    const auto rotation = glm::rotate(-pi_v<float> / 2.0f, glm::vec3{0.0f, 0.0f, 1.0f});

    const glm::vec3 translation{basicWellModel.getInnerRadius(),
                                basicWellModel.getHeight() + basicWellModel.getWheelHeight(), 0.0f};
    setTransformation(glm::translate(translation) * rotation);
}
