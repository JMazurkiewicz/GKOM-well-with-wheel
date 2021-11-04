#include "CompoundModelGenerator.h"

#include <numeric>
#include <ranges>

void CompoundModelGenerator::addGenerator(ModelGenerator& generator) {
    generators.push_back(&generator);
}

unsigned CompoundModelGenerator::getVertexCount() const {
    const auto counts = generators | std::views::transform(&ModelGenerator::getVertexCount);
    return std::reduce(counts.begin(), counts.end());
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
