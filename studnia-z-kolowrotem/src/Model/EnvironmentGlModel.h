#pragma once

#include <glm/glm.hpp>
#include <vector>

class EnvironmentGlModel {
public:
	using Vertices = std::vector<glm::vec3>;
	using Indices = std::vector<unsigned>;

	EnvironmentGlModel() = default;
	explicit EnvironmentGlModel(Vertices&& vertices, Indices&& indices);

	EnvironmentGlModel(const EnvironmentGlModel&) = delete;
	EnvironmentGlModel& operator=(const EnvironmentGlModel&) = delete;
	EnvironmentGlModel(EnvironmentGlModel&&) = default;
	EnvironmentGlModel& operator=(EnvironmentGlModel&&) = default;

	const Vertices& getVertices() const noexcept;
	const Indices& getIndices() const noexcept;

private:
	Vertices vertices;
	Indices indices;
};