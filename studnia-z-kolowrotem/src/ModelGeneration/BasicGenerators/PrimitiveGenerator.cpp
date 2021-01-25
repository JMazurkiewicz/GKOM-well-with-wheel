#include "PrimitiveGenerator.h"

void PrimitiveGenerator::setColor(const glm::vec3& newColor) {
	color = newColor;
}

void PrimitiveGenerator::finishModel() {
	applyTransformation();
	createTexCoords();
	adjustArrayOffset();
}

void PrimitiveGenerator::doColoring() {
	for(Vertex& vertex : vertices) {
		vertex.color = color;
	}
}
