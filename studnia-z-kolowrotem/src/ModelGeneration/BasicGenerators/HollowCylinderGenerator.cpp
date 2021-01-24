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
    return 2 * CylinderGenerator::getVertexCount();
}

unsigned HollowCylinderGenerator::getOuterCyilnderOffset() const {
    return 0;
}

unsigned HollowCylinderGenerator::getInnerCylinderOffset() const {
    return CylinderGenerator::getVertexCount();
}

void HollowCylinderGenerator::constructModel() {
    setRadius(outerRadius);
    CylinderGenerator::constructModel();

    const unsigned firstInnerIndex = indices.size();
    setRadius(innerRadius);
    CylinderGenerator::constructModel();
    adjustInnerIndices(firstInnerIndex);

    connectTop();
}

void HollowCylinderGenerator::adjustInnerIndices(unsigned firstInnerIndex) {
    for(unsigned index = firstInnerIndex; index < indices.size(); ++index) {
        indices[index].advance(getInnerCylinderOffset());
    }
}

void HollowCylinderGenerator::connectTop() {
    for(unsigned index = 0; index < getSampleRate(); ++index) {
        const unsigned next = nextIndex(index);

        indices.push_back({
            index + getOuterCyilnderOffset() + getUpperCircleOffset(),
            index + getInnerCylinderOffset() + getUpperCircleOffset(),
            next + getInnerCylinderOffset() + getUpperCircleOffset()
        });

        indices.push_back({
            index + getOuterCyilnderOffset() + getUpperCircleOffset(),
            next + getOuterCyilnderOffset() + getUpperCircleOffset(),
            next + getInnerCylinderOffset() + getUpperCircleOffset()
        });
    }
}

unsigned HollowCylinderGenerator::nextIndex(unsigned index) const {
    ++index;
    if(index == getSampleRate()) {
        index = 0;
    }
    return index;
}
