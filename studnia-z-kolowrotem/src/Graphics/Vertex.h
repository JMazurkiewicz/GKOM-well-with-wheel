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
	glm::vec3 normal;
	glm::vec2 texture;
};

std::ostream& operator<<(std::ostream& stream, const glm::vec2& vec);
std::ostream& operator<<(std::ostream& stream, const glm::vec3& vec);
std::ostream& operator<<(std::ostream& stream, const Vertex& vertex);

static_assert(std::is_standard_layout_v<Vertex>, "Vertex must be standard layout time");
