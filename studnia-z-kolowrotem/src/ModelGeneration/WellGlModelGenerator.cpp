#include "WellGlModelGenerator.h"

#include <cmath>
#include <iostream>
#include <glm/ext.hpp>
#include <iostream>

WellGlModelGenerator::WellGlModelGenerator(const WellModel& basicModel)
	: basicModel{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} { }

void WellGlModelGenerator::setSampleRate(unsigned newSampleRate) {
	sampleRate = newSampleRate;
}

WellGlModel WellGlModelGenerator::generate() {
	prepareGenerators();
	auto[vertices, indices] = generateModel();
	return WellGlModel{std::move(vertices), std::move(indices)};
}

void WellGlModelGenerator::prepareGenerators() {
	wellBaseGenerator.setInnerRadius(basicModel.getInnerRadius());
	wellBaseGenerator.setOuterRadius(basicModel.getOuterRadius());
	wellBaseGenerator.setHeight(basicModel.getHeight());
	wellBaseGenerator.setSampleRate(sampleRate);
	addGenerator(&wellBaseGenerator);
}
