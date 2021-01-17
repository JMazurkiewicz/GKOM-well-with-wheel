#include "GeneratorBase.h"

GeneratorBase::GeneratorBase() : arrayOffset{0}, transformation{1.0f} { }

void GeneratorBase::setArrayOffset(unsigned newArrayOffset) {
	arrayOffset = newArrayOffset;
}

void GeneratorBase::setTransformation(const glm::mat4& newTransformation) {
	transformation = newTransformation;
}

GeneratorBase::Model GeneratorBase::generateModel() {
	constructModel();
	applyTransformation();
	adjustArrayOffset();
	return Model{std::move(vertices), std::move(indices)};
}

void GeneratorBase::applyTransformation() {
	for(glm::vec3& vec : vertices) {
		vec = glm::vec3{transformation * glm::vec4{vec, 1.0f}};
	}
}

void GeneratorBase::adjustArrayOffset() {
	for(unsigned& index : indices) {
		index += arrayOffset;
	}
}
