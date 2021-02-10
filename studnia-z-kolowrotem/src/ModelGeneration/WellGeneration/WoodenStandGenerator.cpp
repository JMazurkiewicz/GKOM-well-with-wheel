#include "WoodenStandGenerator.h"

#include <glm/ext.hpp>

WoodenStandGenerator::WoodenStandGenerator(const WellModel& basicModel)
	: basicModel{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} { }

void WoodenStandGenerator::setSampleRate(unsigned newSampleRate) {
	sampleRate = newSampleRate;
}

void WoodenStandGenerator::prepareGenerators() {
	prepareLeftBracketGenerator();
	prepareRightBracketGenerator();
	prepareLogGenerator();
}

void WoodenStandGenerator::prepareLeftBracketGenerator() {
	leftBracketGenerator.setRadius(basicModel.getBracketRadius());
	leftBracketGenerator.setHeight(basicModel.getHeight() + basicModel.getBracketHeight());
	leftBracketGenerator.setSampleRate(sampleRate);

	const glm::vec3 translation = {
		-(basicModel.getInnerRadius() - basicModel.getBracketRadius()),
		0.0f, 0.0
	};
	leftBracketGenerator.setTransformation(glm::translate(translation));
	addGenerator(leftBracketGenerator);
}

void WoodenStandGenerator::prepareRightBracketGenerator() {
	rightBracketGenerator.setRadius(basicModel.getBracketRadius());
	rightBracketGenerator.setHeight(basicModel.getHeight() + basicModel.getBracketHeight());
	rightBracketGenerator.setSampleRate(sampleRate);

	const glm::vec3 translation = {
		basicModel.getInnerRadius() - basicModel.getBracketRadius(),
		0.0f, 0.0
	};
	rightBracketGenerator.setTransformation(glm::translate(translation));
	addGenerator(rightBracketGenerator);
}

void WoodenStandGenerator::prepareLogGenerator() {
	logGenerator.setWidth(basicModel.getInnerRadius() * 2.0f);
	logGenerator.setHeight(0.2f);
	logGenerator.setLength(basicModel.getBracketRadius() * 2.0f);
	logGenerator.setTransformation(glm::translate(glm::vec3{0.0f, basicModel.getBracketHeight() + basicModel.getHeight(), 0.0f}));
	addGenerator(logGenerator);
}
