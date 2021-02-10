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

	const glm::vec3 xTranslation = {
		-(basicModel.getInnerRadius() - basicModel.getBracketRadius()),
		0.0f,
		0.0f
	};
	leftBracketGenerator.setTransformation(glm::translate(xTranslation));

	addGenerator(leftBracketGenerator);
}

void WoodenStandGenerator::prepareRightBracketGenerator() {
	rightBracketGenerator.setRadius(basicModel.getBracketRadius());
	rightBracketGenerator.setHeight(basicModel.getHeight() + basicModel.getBracketHeight());
	rightBracketGenerator.setSampleRate(sampleRate);

	const glm::vec3 xTranslation = {
		basicModel.getInnerRadius() - basicModel.getBracketRadius(),
		0.0f,
		0.0f
	};
	rightBracketGenerator.setTransformation(glm::translate(xTranslation));

	addGenerator(rightBracketGenerator);
}

void WoodenStandGenerator::prepareLogGenerator() {
	logGenerator.setWidth(basicModel.getInnerRadius() * 2.0f);
	logGenerator.setHeight(basicModel.getLogHeight());
	logGenerator.setLength(basicModel.getBracketRadius() * 2.0f);

	const glm::vec3 yTranslation = glm::vec3{
		0.0f,
		basicModel.getBracketHeight() + basicModel.getHeight(),
		0.0f
	};
	logGenerator.setTransformation(glm::translate(yTranslation));
	
	addGenerator(logGenerator);
}
