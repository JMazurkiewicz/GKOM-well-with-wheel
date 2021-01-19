#include "ModelGenerator.h"

ModelGenerator::ModelGenerator() : arrayOffset{0}, transformation{1.0f} { }

void ModelGenerator::setArrayOffset(unsigned newArrayOffset) {
	arrayOffset = newArrayOffset;
}

void ModelGenerator::setTransformation(const glm::mat4& newTransformation) {
	transformation = newTransformation;
}

ModelGenerator::Model ModelGenerator::generateModel() {
	constructModel();
	applyTransformation();
	adjustArrayOffset();
	return Model{std::move(vertices), std::move(indices)};
}

void ModelGenerator::applyTransformation() {
	for(glm::vec3& vec : vertices) {
		vec = glm::vec3{transformation * glm::vec4{vec, 1.0f}};
	}
}

void ModelGenerator::adjustArrayOffset() {
	for(unsigned& index : indices) {
		index += arrayOffset;
	}
}
