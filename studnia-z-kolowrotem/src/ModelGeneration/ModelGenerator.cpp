#include "ModelGenerator.h"
#include <iostream>

ModelGenerator::ModelGenerator() : arrayOffset{0}, transformation{1.0f} { }

void ModelGenerator::setArrayOffset(unsigned newArrayOffset) {
	arrayOffset += newArrayOffset;
}

void ModelGenerator::setTransformation(const glm::mat4& newTransformation) {
	transformation = newTransformation;
}

ModelGenerator::Model ModelGenerator::generateModel() {
	constructModel();
	applyTransformation();
	updateNormals();
	adjustArrayOffset();
	return Model{std::move(vertices), std::move(indices)};
}

void ModelGenerator::updateNormals() {

	if (indices.size() < 84) {
		for (unsigned int idx = 0; idx < indices.size(); idx += 3) {
			std::cout << "idx: " << idx << std::endl;
			glm::vec3 A = vertices[indices[idx]].position;
			glm::vec3 B = vertices[indices[idx + 1]].position;
			glm::vec3 C = vertices[indices[idx + 2]].position;

			glm::vec3 perp_vec = glm::cross(B - A, C - A);

			vertices[indices[idx]].normal += perp_vec;
			vertices[indices[idx + 1]].normal += perp_vec;
			vertices[indices[idx + 2]].normal += perp_vec;
		}

		for (unsigned int vec = 0; vec < vertices.size(); vec++) {
			vertices[vec].normal = glm::normalize(vertices[vec].normal);
		}
	}
}

void ModelGenerator::applyTransformation() {
	for(Vertex& vec : vertices) {
		glm::vec3& position = vec.position;
		position = glm::vec3{transformation * glm::vec4{position, 1.0f}};
	}
}

void ModelGenerator::adjustArrayOffset() {
	for(unsigned& index : indices) {
		index += arrayOffset;
	}
}
