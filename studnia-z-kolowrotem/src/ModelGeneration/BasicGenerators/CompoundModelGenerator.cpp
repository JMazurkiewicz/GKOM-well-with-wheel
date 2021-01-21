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
	unsigned offset = 0;

	for(ModelGenerator* generator : generators) {
		generator->setArrayOffset(offset);
		offset += generator->getVertexCount();
		
		auto [newVerticies, newIndicies] = generator->generateModel();
		vertices.insert(vertices.end(), newVerticies.begin(), newVerticies.end());
		indices.insert(indices.end(), newIndicies.begin(), newIndicies.end());
	}
}

void CompoundModelGenerator::finishModel() {
	applyTransformation();
	adjustArrayOffset();
}
