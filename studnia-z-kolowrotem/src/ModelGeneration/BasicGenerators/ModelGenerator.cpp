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
	finishModel();
	return Model{std::move(vertices), std::move(indices)};
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
