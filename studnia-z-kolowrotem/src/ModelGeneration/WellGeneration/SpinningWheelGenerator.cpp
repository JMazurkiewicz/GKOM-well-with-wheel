#include "SpinningWheelGenerator.h"

#include <glm/ext.hpp>

SpinningWheelGenerator::SpinningWheelGenerator(const WellModel& basicWellModel, const WheelModel& basicModel)
	: basicWellModel{basicWellModel}, basicModel{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} { }

void SpinningWheelGenerator::setSampleRate(unsigned newSampleRate) {
	sampleRate = newSampleRate;
}

void SpinningWheelGenerator::prepareGenerators() {
	prepareMiddleElementGenerator();
	prepareRingGenerator();
	prepareCuboidGenerators();
	prepareHoldingCylinderGenerator();
	prepareTransformation();
}

void SpinningWheelGenerator::prepareMiddleElementGenerator() {
	middleElementGenerator.setHeight(basicModel.getHeight());
	middleElementGenerator.setSampleRate(sampleRate);
	middleElementGenerator.setRadius(basicModel.getMiddleElementRadius());
	addGenerator(&middleElementGenerator);
}

void SpinningWheelGenerator::prepareRingGenerator() {
	ringGenerator.setHeight(basicModel.getHeight());
	ringGenerator.setSampleRate(sampleRate);
	ringGenerator.setInnerRadius(basicModel.getInnerRadius());
	ringGenerator.setOuterRadius(basicModel.getOuterRadius());
	addGenerator(&ringGenerator);
}

void SpinningWheelGenerator::prepareCuboidGenerators() {
	cuboidGenerators.resize(basicModel.getConnectorCount());
	const float connectorWidth = basicModel.getInnerRadius();
	const float connectorLength = basicModel.getMiddleElementRadius();

	const float yTranslation = (basicModel.getHeight() - basicModel.getConnectorHeight()) / 2.0f;
	const auto firstTranslation = glm::vec3{basicModel.getInnerRadius() / 2.0f, yTranslation, 0.0f};
	
	const float innerAngle = glm::radians(360.0f / basicModel.getConnectorCount());

	float angle = 0.0f;
	for(CuboidGenerator& generator : cuboidGenerators) {
		generator.setHeight(basicModel.getConnectorHeight());
		generator.setLength(connectorLength);
		generator.setWidth(connectorWidth);
			
		const auto translation = glm::translate(glm::rotateY(firstTranslation, -angle));
		const auto rotation = glm::rotate(-angle, glm::vec3{0.0f, 1.0f, 0.0f});

		generator.setTransformation(translation * rotation);
		addGenerator(&generator);

		angle += innerAngle;
	}
}

void SpinningWheelGenerator::prepareHoldingCylinderGenerator() {
	holdingCylinderGenerator.setSampleRate(sampleRate);

	const float height = 2.0f * (basicWellModel.getInnerRadius() - basicWellModel.getBracketRadius());
	holdingCylinderGenerator.setHeight(height);
	holdingCylinderGenerator.setRadius(1.01f * basicModel.getMiddleElementRadius());
	holdingCylinderGenerator.setTransformation(glm::translate(glm::vec3{0.0f, -height, 0.0f}));
	addGenerator(&holdingCylinderGenerator);
}

void SpinningWheelGenerator::prepareTransformation() {
	const auto rotation = glm::rotate(-glm::half_pi<float>(), glm::vec3{0.0f, 0.0f, 1.0f});

	const glm::vec3 translationVector{basicWellModel.getInnerRadius(), basicWellModel.getWheelHeight(), 0.0f};
	const auto translation = glm::translate(translationVector);
	
	setTransformation(translation * rotation);
}
