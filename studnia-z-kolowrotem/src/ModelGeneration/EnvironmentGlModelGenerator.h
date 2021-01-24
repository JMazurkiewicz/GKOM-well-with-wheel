#pragma once

#include "GlModel/GlModel.h"

class EnvironmentModel;

class EnvironmentGlModelGenerator {
public:
	using Vertices = GlModel::Vertices;
	using Indices = GlModel::Indices;

	explicit EnvironmentGlModelGenerator(const EnvironmentModel& basicModel);
	EnvironmentGlModelGenerator(const EnvironmentGlModelGenerator&) = delete;
	EnvironmentGlModelGenerator& operator=(const EnvironmentGlModelGenerator&) = delete;

	[[nodiscard]] GlModel generate();

private:
	const EnvironmentModel& basicModel;

	Vertices vertices;
	Indices indices;
};