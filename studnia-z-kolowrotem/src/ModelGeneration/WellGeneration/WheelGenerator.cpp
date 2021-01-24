#include "WheelGenerator.h"

#include <glm/ext.hpp>

WheelGenerator::WheelGenerator(const WellModel& basicWellModel, const WheelModel& basicModel)
	: basicWellModel{basicWellModel}, basicWheelModel{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} { }

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
	middleElementGenerator.setHeight(basicWheelModel.getHeight());
	middleElementGenerator.setSampleRate(sampleRate);
	middleElementGenerator.setRadius(basicWheelModel.getMiddleElementRadius());
	addGenerator(&middleElementGenerator);
}

void WheelGenerator::prepareRingGenerator() {
	ringGenerator.setHeight(basicWheelModel.getHeight());
	ringGenerator.setSampleRate(sampleRate);
	ringGenerator.setInnerRadius(basicWheelModel.getInnerRadius());
	ringGenerator.setOuterRadius(basicWheelModel.getOuterRadius());
	addGenerator(&ringGenerator);
}

void WheelGenerator::prepareCuboidGenerators() {
	cuboidGenerators.resize(basicWheelModel.getConnectorCount());
	const float connectorWidth = basicWheelModel.getInnerRadius();
	const float connectorLength = basicWheelModel.getMiddleElementRadius();

	const float yTranslation = (basicWheelModel.getHeight() - basicWheelModel.getConnectorHeight()) / 2.0f;
	const auto firstTranslation = glm::vec3{basicWheelModel.getInnerRadius() / 2.0f, yTranslation, 0.0f};
	
	const float innerAngle = glm::radians(360.0f / basicWheelModel.getConnectorCount());

	float angle = 0.0f;
	for(CuboidGenerator& generator : cuboidGenerators) {
		generator.setHeight(basicWheelModel.getConnectorHeight());
		generator.setLength(connectorLength);
		generator.setWidth(connectorWidth);
			
		const auto translation = glm::translate(glm::rotateY(firstTranslation, -angle));
		const auto rotation = glm::rotate(-angle, glm::vec3{0.0f, 1.0f, 0.0f});

		generator.setTransformation(translation * rotation);
		addGenerator(&generator);

		angle += innerAngle;
	}
}

void WheelGenerator::prepareHoldingCylinderGenerator() {
	holdingCylinderGenerator.setSampleRate(sampleRate);

	const float height = 2.0f * (basicWellModel.getInnerRadius() - basicWellModel.getBracketRadius());
	holdingCylinderGenerator.setHeight(height);
	holdingCylinderGenerator.setRadius(1.01f * basicWheelModel.getMiddleElementRadius());
	holdingCylinderGenerator.setTransformation(glm::translate(glm::vec3{0.0f, -height, 0.0f}));
	addGenerator(&holdingCylinderGenerator);
}

void WheelGenerator::prepareTransformation() {
	const auto rotation = glm::rotate(-glm::half_pi<float>(), glm::vec3{0.0f, 0.0f, 1.0f});

	const glm::vec3 translationVector{basicWellModel.getInnerRadius(), basicWellModel.getWheelHeight(), 0.0f};
	const auto translation = glm::translate(translationVector);
	
	setTransformation(translation * rotation);
}
