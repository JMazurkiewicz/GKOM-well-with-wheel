#include "Vertex.h"

Vertex::Vertex()
	: position{}, color{}, normal{}, texture{} { }

Vertex::Vertex(const glm::vec3& position)
	: position{position}, color{}, normal{}, texture{} { }
