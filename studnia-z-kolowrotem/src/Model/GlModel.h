#pragma once

#include <glm/glm.hpp>
#include <vector>

class GlModel {
public:
	using Vertices = std::vector<glm::vec3>;
	using Indices = std::vector<unsigned>;

	GlModel() = default;
	explicit GlModel(Vertices&& vertices, Indices&& indices);

	GlModel(const GlModel&) = delete;
	GlModel& operator=(const GlModel&) = delete;
	GlModel(GlModel&&) = default;
	GlModel& operator=(GlModel&&) = default;

	const Vertices& getVertices() const noexcept;
	const Indices& getIndices() const noexcept;

protected:
	Vertices vertices;
	Indices indices;
};
