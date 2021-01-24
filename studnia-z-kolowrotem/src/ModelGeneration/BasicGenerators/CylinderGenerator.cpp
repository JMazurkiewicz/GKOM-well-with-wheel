#include "CylinderGenerator.h"

#include <glm/ext.hpp>

CylinderGenerator::CylinderGenerator()
    : radius{1.0f}, height{1.0f} { }

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
    return getSampleRate() + 1U;
}

unsigned CylinderGenerator::getLowerCircleOffset() const {
    return 0;
}

unsigned CylinderGenerator::getUpperCircleOffset() const {
    return getSampleCount();
}

void CylinderGenerator::constructModel() {
    createLowerCircle();
    createUpperCircle();
    connectSides();
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
    glm::vec3 pattern = start;
    const float angle = glm::two_pi<float>() / getSampleRate();

    for(unsigned index = 0; index < getSampleCount(); ++index) {
        vertices.push_back(pattern);
        pattern = glm::rotateY(pattern, angle);
    }
}

void CylinderGenerator::connectSides() {
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
    float left = dx;
    float right = 0.0f;

    for(unsigned index = 0; index < getSampleCount(); ++index) {
        const unsigned upperIndex = index + getUpperCircleOffset();

        vertices[index].texture = glm::vec2(right, 0.0f);
        vertices[upperIndex].texture = glm::vec2(right, 1.0f);

        right += dx;
        left += dx;
    }
}
