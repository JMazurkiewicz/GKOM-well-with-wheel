#include "Vertex.h"

Vertex::Vertex()
	: position{}, color{}, normal{}, texture{} { }

Vertex::Vertex(const glm::vec3& position)
	: position{position}, color{}, normal{}, texture{} { }

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex) {
	return stream
		<< "{\"position\": [" << vertex.position.x << ", " << vertex.position.y << ", " << vertex.position.z << "], \"color\": ["
		<< vertex.color.x << ", " << vertex.color.y << ", " << vertex.color.z << "], \"normal\": ["
		<< vertex.normal.x << vertex.normal.y << vertex.normal.z << "], \"texture\": ["
		<< vertex.texture.x << ", " << vertex.texture.y << "]}";
}
