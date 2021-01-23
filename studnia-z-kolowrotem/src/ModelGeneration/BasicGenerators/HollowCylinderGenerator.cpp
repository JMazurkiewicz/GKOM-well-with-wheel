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
    for(unsigned index = 0; index < getSampleRate(); ++index) {
        const unsigned next = nextIndex(index);

        const IndexGroup firstTriangle{
            index + getOuterCyilnderOffset() + getUpperCircleOffset(),
            index + getInnerCylinderOffset() + getUpperCircleOffset(),
            next + getInnerCylinderOffset() + getUpperCircleOffset()
        };
        indices.push_back(firstTriangle);

        const IndexGroup secondTriangle{
            index + getOuterCyilnderOffset() + getUpperCircleOffset(),
            next + getOuterCyilnderOffset() + getUpperCircleOffset(),
            next + getInnerCylinderOffset() + getUpperCircleOffset()
        };
        indices.push_back(secondTriangle);
    }
}

unsigned HollowCylinderGenerator::nextIndex(unsigned index) const {
    ++index;
    if(index == getSampleRate()) {
        index = 0;
    }
    return index;
}
