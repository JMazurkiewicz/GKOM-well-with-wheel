#include "PlaneGenerator.h"
#pragma once

PlaneGenerator::PlaneGenerator()
	: width{1.0f}, length{1.0f} { }

void PlaneGenerator::setWidth(float newWidth) {
	width = newWidth;
}

void PlaneGenerator::setLength(float newLength) {
	length = newLength;
}

unsigned PlaneGenerator::getVertexCount() const {
	return 4;
}

void PlaneGenerator::constructModel() {
	vertices.emplace_back(-width, 0.0f, -length);
	vertices.emplace_back(-width, 0.0f, +length);
	vertices.emplace_back(+width, 0.0f, +length);
	vertices.emplace_back(+width, 0.0f, -length);

	indices.push_back({0, 2, 1});
	indices.push_back({0, 3, 2});
}

void PlaneGenerator::createTexCoords() {
	vertices[0].texture = glm::vec2(0.0f, 1.0f);
	vertices[1].texture = glm::vec2(0.0f, 0.0f);
	vertices[2].texture = glm::vec2(1.0f, 0.0f);
	vertices[3].texture = glm::vec2(1.0f, 1.0f);
}
