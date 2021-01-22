#include "HollowCylinderGenerator.h"

HollowCylinderGenerator::HollowCylinderGenerator()
    : CylinderGenerator(), innerRadius{1.0f}, outerRadius{1.0f} { }

void HollowCylinderGenerator::setInnerRadius(float newInnerRadius) {
    innerRadius = newInnerRadius;
}

void HollowCylinderGenerator::setOuterRadius(float newOuterRadius) {
    outerRadius = newOuterRadius;
}

unsigned HollowCylinderGenerator::getVertexCount() const {
    return 4 * getSampleRate();
}

unsigned HollowCylinderGenerator::getOuterCyilnderOffset() const {
    return 0;
}

unsigned HollowCylinderGenerator::getInnerCylinderOffset() const {
    return 2 * getSampleRate();
}

#include <iostream>
void HollowCylinderGenerator::constructModel() {
    setRadius(outerRadius);
    CylinderGenerator::constructModel();

    setRadius(innerRadius);
    CylinderGenerator::constructModel();
    adjustInnerIndices();

    connectTop();
}

void HollowCylinderGenerator::adjustInnerIndices() {
    for(unsigned index = getInnerCylinderOffset(); index < indices.size(); ++index) {
        indices[index].advance(getInnerCylinderOffset());
    }
}

void HollowCylinderGenerator::connectTop() {
    for(unsigned index = 0; index < CylinderGenerator::getVertexCount(); ++index) {
        const unsigned next = nextIndex(index);

        const IndexGroup firstTriangle{
            index + getOuterCyilnderOffset(),
            index + getInnerCylinderOffset(),
            next + getInnerCylinderOffset()
        };
        indices.push_back(firstTriangle);

        const IndexGroup secondTriangle{
            index + getOuterCyilnderOffset(),
            next + getOuterCyilnderOffset(),
            next + getInnerCylinderOffset()
        };
        indices.push_back(secondTriangle);
    }
}

unsigned HollowCylinderGenerator::nextIndex(unsigned index) const {
    ++index;
    if(index == CylinderGenerator::getVertexCount()) {
        index = 0;
    }
    return index;
}
