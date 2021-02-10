#include "ModelGenerator.h"

ModelGenerator::ModelGenerator() : arrayOffset{0}, transformation{1.0f} { }

void ModelGenerator::setArrayOffset(unsigned newArrayOffset) {
	arrayOffset += newArrayOffset;
}

void ModelGenerator::setTransformation(const glm::mat4& newTransformation) {
	transformation = newTransformation;
}

GlModel ModelGenerator::generateModel() {
	constructModel();
	finishModel();
	return GlModel{std::move(vertices), std::move(indices)};
}

void ModelGenerator::applyTransformation() {
	for(Vertex& vec : vertices) {
		glm::vec3& position = vec.position;
		position = glm::vec3{transformation * glm::vec4{position, 1.0f}};
	}
}

void ModelGenerator::adjustArrayOffset() {
	for(IndexGroup& index : indices) {
		index.advance(arrayOffset);
	}
}
