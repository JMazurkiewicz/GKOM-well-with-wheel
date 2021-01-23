
#include "CuboidGenerator.h"

CuboidGenerator::CuboidGenerator()
	: length{1.0f}, width{1.0f}, height{1.0f} { }

void CuboidGenerator::setLength(float newLength) {
	length = newLength;
}

void CuboidGenerator::setWidth(float newWidth) {
	width = newWidth;
}

void CuboidGenerator::setHeight(float newHeight) {
	height = newHeight;
}

unsigned CuboidGenerator::getVertexCount() const {
	return 8;
}

void CuboidGenerator::constructModel() {
	constructVertices();
	connectVertices();
}

void CuboidGenerator::constructVertices() {
	const float halfX = width / 2.0f;
	const float halfZ = length / 2.0f;

	vertices = {
		glm::vec3{halfX, 0.0f, -halfZ},//Vertex{{halfX, 0.0f, -halfZ},{},{},{1,0}},
		glm::vec3{-halfX, 0.0f, -halfZ},
		glm::vec3{-halfX, 0.0f, halfZ},
		glm::vec3{halfX, 0.0f, halfZ},
		glm::vec3{halfX, height, -halfZ},
		glm::vec3{-halfX, height, -halfZ},
		glm::vec3{-halfX, height, halfZ},
		glm::vec3{halfX, height, halfZ},
	};
}

void CuboidGenerator::connectVertices() {
	indices.push_back({0, 1, 2});
	indices.push_back({0, 3, 2});
	indices.push_back({0, 1, 5});
	indices.push_back({0, 4, 5});
	indices.push_back({0, 3, 7});
	indices.push_back({0, 4, 7});
	indices.push_back({2, 3, 7});
	indices.push_back({2, 6, 7});
	indices.push_back({1, 2, 6});
	indices.push_back({1, 5, 6});
	indices.push_back({4, 5, 6});
	indices.push_back({4, 7, 6});
}
