#pragma once

#include <glm/glm.hpp>
#include <ostream>
#include <type_traits>

struct alignas(float) Vertex {
	Vertex();
	Vertex(const glm::vec3& position);
	Vertex(float x, float y, float z);

	glm::vec3 position;
	glm::vec3 color;
	glm::vec2 texture;
};

static_assert(std::is_standard_layout_v<Vertex>, "Vertex must be standard layout time");
