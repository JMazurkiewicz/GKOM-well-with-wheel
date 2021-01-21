#include "WellGlModelGenerator.h"

#include <cmath>
#include <iostream>
#include <glm/ext.hpp>

WellGlModelGenerator::WellGlModelGenerator(const WellModel& basicModel)
	: basicModel{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} { }

void WellGlModelGenerator::setSampleRate(unsigned newSampleRate) {
	sampleRate = newSampleRate;
}

WellGlModel WellGlModelGenerator::generate() {
	prepareGenerators();
	ModelGenerator::Model model = generateModel();
	for(auto&& x : std::get<0>(model)) {
		std::cout << x << '\n';
	}
	return WellGlModel{std::move(std::get<0>(model)), std::move(std::get<1>(model))};
}

void WellGlModelGenerator::prepareGenerators() {
	//prepareWellBaseGenerator();
	//prepareLeftBracketGenerator();
	//prepareRightBracketGenerator();
	prepareLog();
}

void WellGlModelGenerator::prepareWellBaseGenerator() {
	wellBaseGenerator.setInnerRadius(basicModel.getInnerRadius());
	wellBaseGenerator.setOuterRadius(basicModel.getOuterRadius());
	wellBaseGenerator.setHeight(basicModel.getHeight());
	wellBaseGenerator.setSampleRate(sampleRate);
	addGenerator(&wellBaseGenerator);
}

void WellGlModelGenerator::prepareLeftBracketGenerator() {
	leftBracketGenerator.setRadius(basicModel.getBracketRadius());
	leftBracketGenerator.setHeight(basicModel.getHeight() + basicModel.getBracketHeight());
	leftBracketGenerator.setSampleRate(sampleRate);

	const glm::vec3 translation = {
		-(basicModel.getInnerRadius() - basicModel.getBracketRadius()),
		0.0f, 0.0
	};
	leftBracketGenerator.setTransformation(glm::translate(translation));
	addGenerator(&leftBracketGenerator);
}

void WellGlModelGenerator::prepareRightBracketGenerator() {
	rightBracketGenerator.setRadius(basicModel.getBracketRadius());
	rightBracketGenerator.setHeight(basicModel.getHeight() + basicModel.getBracketHeight());
	rightBracketGenerator.setSampleRate(sampleRate);

	const glm::vec3 translation = {
		basicModel.getInnerRadius() - basicModel.getBracketRadius(),
		0.0f, 0.0
	};
	rightBracketGenerator.setTransformation(glm::translate(translation));
	addGenerator(&rightBracketGenerator);
}

void WellGlModelGenerator::prepareLog() {
	logGenerator.setWidth(basicModel.getInnerRadius() * 2.0f);
	logGenerator.setHeight(0.2f);
	logGenerator.setLength(basicModel.getBracketRadius() * 2.0f);
	logGenerator.setTransformation(glm::translate(glm::vec3{0.0f, basicModel.getBracketHeight() + basicModel.getHeight(), 0.0f}));
	addGenerator(&logGenerator);
}
