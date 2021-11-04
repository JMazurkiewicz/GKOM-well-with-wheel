#include "HollowCylinderGenerator.h"

#include <array>
#include <ranges>

namespace views = std::views;

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

    setRadius(innerRadius);
    CylinderGenerator::createVertices();
}

void HollowCylinderGenerator::createIndices() {
    CylinderGenerator::createIndices();
    CylinderGenerator::createIndices();
    adjustInnerIndices();
    connectTop();
}

void HollowCylinderGenerator::adjustInnerIndices() {
    const unsigned innerCylinderOffset = getInnerCylinderOffset();
    for(IndexGroup& indexGroup : indices | views::drop(innerCylinderOffset - 2)) {
        indexGroup.advance(innerCylinderOffset);
    }
}

void HollowCylinderGenerator::connectTop() {
    for(unsigned index = 0; index < getSampleRate(); ++index) {
        const unsigned outerUpperIndex = index + getUpperCircleOffset() + getOuterCyilnderOffset();
        const unsigned outerUpperNext = outerUpperIndex + 1;
        const unsigned innerUpperIndex = index + getUpperCircleOffset() + getInnerCylinderOffset();
        const unsigned innerUpperNext = innerUpperIndex + 1;

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
        vertices[outerLowerIndex].texture = {xTex, yTex[0]};

        const unsigned outerUpperIndex = index + getUpperCircleOffset() + getOuterCyilnderOffset();
        vertices[outerUpperIndex].texture = {xTex, yTex[1]};

        const unsigned innerUpperIndex = index + getUpperCircleOffset() + getInnerCylinderOffset();
        vertices[innerUpperIndex].texture = {xTex, yTex[2]};

        const unsigned innerLowerIndex = index + getLowerCircleOffset() + getInnerCylinderOffset();
        vertices[innerLowerIndex].texture = {xTex, yTex[3]};

        xTex += dx;
    }
}
