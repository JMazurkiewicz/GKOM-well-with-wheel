#pragma once

#include <glm/glm.hpp>
#include <ostream>
#include <vector>

/**
 * @brief Displayable well model.
 */
class WellGlModel {
public:
	using Vertices = std::vector<glm::vec3>;
	using Indices = std::vector<unsigned>;
	using Normals = std::vector<glm::vec3>;

	WellGlModel() = default;
	explicit WellGlModel(Vertices&& vertices, Indices&& indices, Normals&& normals);

	WellGlModel(const WellGlModel&) = delete;
	WellGlModel& operator=(const WellGlModel&) = delete;
	WellGlModel(WellGlModel&&) = default;
	WellGlModel& operator=(WellGlModel&&) = default;

	const Vertices& getVertices() const;
	const Indices& getIndices() const;
	const Normals& getNormals() const;

private:
	Vertices vertices;
	Indices indices;
	Normals normals;
};
