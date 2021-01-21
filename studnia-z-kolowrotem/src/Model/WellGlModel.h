#pragma once

#include "ModelGeneration/BasicGenerators/ModelGenerator.h"
#include <glm/glm.hpp>
#include <ostream>
#include <vector>

/**
 * @brief Displayable well model.
 */
class WellGlModel {
public:
	using Vertices = ModelGenerator::Vertices;
	using Indices = ModelGenerator::Indices;

	WellGlModel() = default;
	explicit WellGlModel(Vertices&& vertices, Indices&& indices);

	WellGlModel(const WellGlModel&) = delete;
	WellGlModel& operator=(const WellGlModel&) = delete;
	WellGlModel(WellGlModel&&) = default;
	WellGlModel& operator=(WellGlModel&&) = default;

	const Vertices& getVertices() const;
	const Indices& getIndices() const;

private:
	Vertices vertices;
	Indices indices;
};
