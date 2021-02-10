#include "CompoundModelGenerator.h"

void CompoundModelGenerator::addGenerator(ModelGenerator* generator) {
	generators.push_back(generator);
}

unsigned CompoundModelGenerator::getVertexCount() const {
	unsigned count = 0;
	for(ModelGenerator* generator : generators) {
		count += generator->getVertexCount();
	}
	return count;
}

void CompoundModelGenerator::constructModel() {
	prepareGenerators();
	unsigned offset = 0;

	for(ModelGenerator* generator : generators) {
		generator->setArrayOffset(offset);
		offset += generator->getVertexCount();
		
		const auto model = generator->generateModel();
		vertices.insert(vertices.end(), model.getVertices().begin(), model.getVertices().end());
		indices.insert(indices.end(), model.getIndices().begin(), model.getIndices().end());
	}
}

void CompoundModelGenerator::finishModel() {
	applyTransformation();
	adjustArrayOffset();
}
