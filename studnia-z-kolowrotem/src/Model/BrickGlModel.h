#pragma once

#include <array>
#include <gl/glew.h>
#include <glm/glm.hpp>
#include <iostream>

class BrickGlModel {
public:
	using VertexArray = std::array<glm::vec3, 8>;

	static constexpr std::array<GLuint, 36> INDEX_ARRAY = {
		0, 1, 2,
		0, 2, 3,
		0, 4, 5,
		0, 1, 5,
		4, 5, 6,
		4, 6, 7,
		1, 5, 6,
		1, 2, 6,
		0, 3, 4,
		0, 4, 7,
		2, 3, 6,
		2, 6, 7
	};

	BrickGlModel();

	BrickGlModel(const BrickGlModel&) = delete;
	BrickGlModel& operator=(const BrickGlModel&) = delete;
	BrickGlModel(BrickGlModel&&) = default;
	BrickGlModel& operator=(BrickGlModel&&) = default;

	const VertexArray& getVertexArray() const;

	friend std::ostream& operator<<(std::ostream & stream, const BrickGlModel& model);

private:
	friend class BrickGlModelGenerator;
	VertexArray vertices;
};
