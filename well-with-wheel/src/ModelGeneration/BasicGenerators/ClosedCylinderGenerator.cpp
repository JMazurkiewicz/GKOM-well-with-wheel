#include "ClosedCylinderGenerator.h"

void ClosedCylinderGenerator::createIndices() {
    if(getSampleRate() >= 4) {
        createConnections();
    }
}

void ClosedCylinderGenerator::createConnections() {
    const auto nextIndex = [this](unsigned index) {
        return (++index == getSampleRate() ? 0u : index);
    };

    const unsigned lastIndex = getSampleRate() - 1;
    for(unsigned index = 1; index < lastIndex; ++index) {
        const unsigned next = nextIndex(index);

        indices.push_back({getUpperCircleOffset(), index + getUpperCircleOffset(), next + getUpperCircleOffset()});

        indices.push_back({getLowerCircleOffset(), index + getLowerCircleOffset(), next + getLowerCircleOffset()});
    }
}
