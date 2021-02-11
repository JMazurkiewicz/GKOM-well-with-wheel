#include "ModelGenerator.h"

void ModelGenerator::setArrayOffset(unsigned newArrayOffset) {
	arrayOffset = newArrayOffset;
}

void ModelGenerator::setTransformation(const glm::mat4& newTransformation) {
	transformation = newTransformation;
}

GlModel ModelGenerator::generateModel() {
	constructModel();
	applyTransformation();
	adjustArrayOffset();
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
