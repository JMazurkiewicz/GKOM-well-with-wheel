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

	WellGlModel() = default;
	explicit WellGlModel(Vertices&& vertices, Indices&& indices);

	WellGlModel(const WellGlModel&) = delete;
	WellGlModel& operator=(const WellGlModel&) = delete;
	WellGlModel(WellGlModel&&) = default;
	WellGlModel& operator=(WellGlModel&&) = default;

	const Vertices& getVertices() const;
	const Indices& getIndices() const;

	friend std::ostream& operator<<(std::ostream& stream, const WellGlModel& model);

private:
	Vertices vertices;
	Indices indices;
};
