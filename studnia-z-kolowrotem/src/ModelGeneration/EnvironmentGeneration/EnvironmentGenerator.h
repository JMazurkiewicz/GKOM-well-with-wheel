#pragma once

#include "../BasicGenerators/CompoundModelGenerator.h"
#include "../BasicGenerators/PlaneGenerator.h"
#include "../BasicGenerators/CylinderGenerator.h"
#include "GlModel/GlModel.h"
#include "Model/EnvironmentModel.h"

class EnvironmentGenerator : public CompoundModelGenerator {
public:
	using Vertices = GlModel::Vertices;
	using Indices = GlModel::Indices;

	explicit EnvironmentGenerator(const EnvironmentModel& basicModel);

private:
	void prepareGenerators() override;
	void prepareGrassGenrator();
	void prepareLandscapeGenerator();
	
	const EnvironmentModel& basicModel;

	PlaneGenerator grassGenerator;
	CylinderGenerator landscapeGenerator;
};