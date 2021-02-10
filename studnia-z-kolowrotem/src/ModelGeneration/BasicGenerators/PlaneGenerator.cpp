#include "PlaneGenerator.h"

void PlaneGenerator::setWidth(float newWidth) {
	width = newWidth;
}

void PlaneGenerator::setLength(float newLength) {
	length = newLength;
}

unsigned PlaneGenerator::getVertexCount() const {
	return 4;
}

void PlaneGenerator::createVertices() {
	vertices.emplace_back(-width, 0.0f, -length);
	vertices.emplace_back(-width, 0.0f, +length);
	vertices.emplace_back(+width, 0.0f, +length);
	vertices.emplace_back(+width, 0.0f, -length);
}

void PlaneGenerator::createIndices() {
	indices.push_back({0, 2, 1});
	indices.push_back({0, 3, 2});
}

void PlaneGenerator::createTexCoords() {
	vertices[0].texture = {0.0f, 1.0f};
	vertices[1].texture = {0.0f, 0.0f};
	vertices[2].texture = {1.0f, 0.0f};
	vertices[3].texture = {1.0f, 1.0f};
}
