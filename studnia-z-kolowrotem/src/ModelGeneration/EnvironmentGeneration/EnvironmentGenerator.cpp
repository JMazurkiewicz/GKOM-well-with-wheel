#include "EnvironmentGenerator.h"

#include "Model/EnvironmentModel.h"

EnvironmentGenerator::EnvironmentGenerator(const EnvironmentModel& basicModel)
	: basicModel{basicModel} { }

void EnvironmentGenerator::prepareGenerators() {
	prepareGrassGenrator();
	prepareLandscapeGenerator();
}

void EnvironmentGenerator::prepareGrassGenrator() {
	grassGenerator.setLength(basicModel.getSize());
	grassGenerator.setWidth(basicModel.getSize());
	addGenerator(&grassGenerator);
}

void EnvironmentGenerator::prepareLandscapeGenerator() {
	landscapeGenerator.setHeight(basicModel.getHeight());
	landscapeGenerator.setRadius(basicModel.getSize() / 2.0f);
	addGenerator(&landscapeGenerator);
}
