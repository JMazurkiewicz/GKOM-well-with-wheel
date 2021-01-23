#include "WellBaseGenerator.h"

WellBaseGenerator::WellBaseGenerator(const WellModel& basicModel)
	: basicModel{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} { }

void WellBaseGenerator::setSampleRate(unsigned newSampleRate) {
	sampleRate = newSampleRate;
}

void WellBaseGenerator::prepareGenerators() {
	baseGenerator.setInnerRadius(basicModel.getInnerRadius());
	baseGenerator.setOuterRadius(basicModel.getOuterRadius());
	baseGenerator.setHeight(basicModel.getHeight());
	baseGenerator.setSampleRate(sampleRate);
	//baseGenerator.setColor(glm::vec3{0.5f, 0.5f, 0.5f});
	addGenerator(&baseGenerator);
}
