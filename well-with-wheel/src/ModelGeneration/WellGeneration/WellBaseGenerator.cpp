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
	addGenerator(baseGenerator);
}
