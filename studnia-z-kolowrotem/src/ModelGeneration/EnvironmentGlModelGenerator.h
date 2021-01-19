#pragma once

#include "Model/EnvironmentGlModel.h"

class EnvironmentModel;

class EnvironmentGlModelGenerator {
public:
	using Vertices = EnvironmentGlModel::Vertices;
	using Indices = EnvironmentGlModel::Indices;

	explicit EnvironmentGlModelGenerator(const EnvironmentModel& basicModel);
	EnvironmentGlModelGenerator(const EnvironmentGlModelGenerator&) = delete;
	EnvironmentGlModelGenerator& operator=(const EnvironmentGlModelGenerator&) = delete;

	[[nodiscard]] EnvironmentGlModel generate();

private:
	const EnvironmentModel& basicModel;

	Vertices vertices;
	Indices indices;
};