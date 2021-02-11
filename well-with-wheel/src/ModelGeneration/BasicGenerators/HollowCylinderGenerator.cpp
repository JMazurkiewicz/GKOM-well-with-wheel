#include "HollowCylinderGenerator.h"

#include <array>

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

void HollowCylinderGenerator::createVertices() {
    setRadius(outerRadius);
    CylinderGenerator::createVertices();
    CylinderGenerator::createIndices();
    
    setRadius(innerRadius);
    CylinderGenerator::createVertices();
    CylinderGenerator::createIndices();
}

void HollowCylinderGenerator::createIndices() {
    const unsigned firstInnerIndex = CylinderGenerator::getVertexCount();
    adjustInnerIndices(firstInnerIndex);
    connectTop();
}

void HollowCylinderGenerator::adjustInnerIndices(unsigned firstInnerIndex) {
    for(unsigned index = firstInnerIndex; index < indices.size(); ++index) {
        indices[index].advance(getInnerCylinderOffset());
    }
}

void HollowCylinderGenerator::connectTop() {
    const auto nextIndex = [this](unsigned index) {
        return (++index == getSampleRate() ? 0u : index);
    };

    for(unsigned index = 0; index < getSampleRate(); ++index) {
        const unsigned outerUpperIndex = index + getUpperCircleOffset() + getOuterCyilnderOffset();
        const unsigned outerUpperNext = nextIndex(outerUpperIndex);
        const unsigned innerUpperIndex = index + getUpperCircleOffset() + getInnerCylinderOffset();
        const unsigned innerUpperNext = nextIndex(innerUpperIndex);

        indices.push_back({innerUpperIndex, outerUpperNext, innerUpperNext});
        indices.push_back({innerUpperIndex, outerUpperIndex, outerUpperNext});
    }
}

void HollowCylinderGenerator::createTexCoords() {
    constexpr std::array yTex = {0.0f, 1.0f, 0.5f, 1.0f};
    const float dx = 4.0f / getSampleRate();

    float xTex = 0.0f;

    for(unsigned index = 0; index < getSampleCount(); ++index) {
        const unsigned outerLowerIndex = index + getLowerCircleOffset() + getOuterCyilnderOffset();
        vertices[outerLowerIndex].texture = glm::vec2{xTex, yTex[0]};

        const unsigned outerUpperIndex = index + getUpperCircleOffset() + getOuterCyilnderOffset();
        vertices[outerUpperIndex].texture = glm::vec2{xTex, yTex[1]};
        
        const unsigned innerUpperIndex = index + getUpperCircleOffset() + getInnerCylinderOffset();
        vertices[innerUpperIndex].texture = glm::vec2{xTex, yTex[2]};
        
        const unsigned innerLowerIndex = index + getLowerCircleOffset() + getInnerCylinderOffset();
        vertices[innerLowerIndex].texture = glm::vec2{xTex, yTex[3]};

        xTex += dx;
    }
}
