#include "HollowCylinderGenerator.h"

#include <array>

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
        const unsigned outerUpperIndex = index + getUpperCircleOffset() + getOuterCyilnderOffset();
        const unsigned outerUpperNext = nextIndex(outerUpperIndex);
        const unsigned innerUpperIndex = index + getUpperCircleOffset() + getInnerCylinderOffset();
        const unsigned innerUpperNext = nextIndex(innerUpperIndex);

        indices.push_back({innerUpperIndex, outerUpperNext, innerUpperNext});
        indices.push_back({innerUpperIndex, outerUpperIndex, outerUpperNext});
    }
}

unsigned HollowCylinderGenerator::nextIndex(unsigned index) const {
    ++index;
    if(index == getSampleRate()) {
        index = 0;
    }
    return index;
}

void HollowCylinderGenerator::createTexCoords() {
    const float dx = 4.0f / getSampleRate();
    constexpr std::array yTex = {0.0f, 1.0f, 0.5f, 1.0f};

    float xTex = 0.0f;

    for(unsigned index = 0; index < getSampleCount(); ++index) {
        const unsigned outerLowerIndex = index + getLowerCircleOffset() + getOuterCyilnderOffset();
        const unsigned outerUpperIndex = index + getUpperCircleOffset() + getOuterCyilnderOffset();
        const unsigned innerUpperIndex = index + getUpperCircleOffset() + getInnerCylinderOffset();
        const unsigned innerLowerIndex = index + getLowerCircleOffset() + getInnerCylinderOffset();

        vertices[outerLowerIndex].texture = glm::vec2{xTex, yTex[0]};
        vertices[outerUpperIndex].texture = glm::vec2{xTex, yTex[1]};
        vertices[innerUpperIndex].texture = glm::vec2{xTex, yTex[2]};
        vertices[innerLowerIndex].texture = glm::vec2{xTex, yTex[3]};

        xTex += dx;
    }
}
