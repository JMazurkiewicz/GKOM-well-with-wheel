#include "CylinderGenerator.h"

#include <glm/ext.hpp>
#include <numbers>

using namespace std::numbers;

void CylinderGenerator::setRadius(float newRadius) {
    radius = newRadius;
}

void CylinderGenerator::setHeight(float newHeight) {
    height = newHeight;
}

unsigned CylinderGenerator::getVertexCount() const {
    return 2 * getSampleCount();
}

unsigned CylinderGenerator::getSampleCount() const {
    return getSampleRate() + 1u;
}

unsigned CylinderGenerator::getLowerCircleOffset() const {
    return 0;
}

unsigned CylinderGenerator::getUpperCircleOffset() const {
    return getSampleCount();
}

void CylinderGenerator::createVertices() {
    createLowerCircle();
    createUpperCircle();
}

void CylinderGenerator::createLowerCircle() {
    const glm::vec3 start{radius, 0.0f, 0.0f};
    createCircle(start);
}

void CylinderGenerator::createUpperCircle() {
    const glm::vec3 start{radius, height, 0.0f};
    createCircle(start);
}

void CylinderGenerator::createCircle(const glm::vec3& start) {
    const float angle = 2.0f * pi_v<float> / getSampleRate();

    glm::vec3 pattern = start;
    for(unsigned index = 0; index < getSampleCount(); ++index) {
        vertices.push_back(pattern);
        pattern = glm::rotateY(pattern, angle);
    }
}

void CylinderGenerator::createIndices() {
    for(unsigned index = 0; index < getSampleRate(); ++index) {
        const unsigned next = index + 1;
        const unsigned upperIndex = index + getUpperCircleOffset();
        const unsigned upperNext = upperIndex + 1;

        indices.push_back({index, next, upperNext});
        indices.push_back({index, upperIndex, upperNext});
    }
}

void CylinderGenerator::createTexCoords() {
    const float dx = 4.0f / getSampleRate();
    float xTex = 0.0f;

    for(unsigned index = 0; index < getSampleCount(); ++index) {
        const unsigned upperIndex = index + getUpperCircleOffset();

        vertices[index].texture = {xTex, 0.0f};
        vertices[upperIndex].texture = {xTex, 1.0f};

        xTex += dx;
    }
}
