#include "Vertex.h"

Vertex::Vertex()
	: position{}, color{}, normal{}, texture{} { }

Vertex::Vertex(const glm::vec3& position)
	: position{position}, color{}, normal{}, texture{} { }

std::ostream& operator<<(std::ostream& stream, const glm::vec3& vec) {
	return stream << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]";
}

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
	return stream
		<< "{\"position\": [" << vertex.position << "], \"color\": ["
		<< vertex.color << "], \"normal\": ["
		<< vertex.normal << "], \"texture\": ["
		<< vertex.texture.x << ", " << vertex.texture.y << "]}";
}
