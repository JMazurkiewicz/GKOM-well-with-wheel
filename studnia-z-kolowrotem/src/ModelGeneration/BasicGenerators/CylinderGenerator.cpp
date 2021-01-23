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
    return 2 * getSampleRate();
}

unsigned CylinderGenerator::getLowerCircleOffset() const {
    return 0;
}

unsigned CylinderGenerator::getUpperCircleOffset() const {
    return getSampleRate();
}

void CylinderGenerator::constructModel() {
    createLowerCircle();
    createUpperCircle();
    connectSides();
    createTexCoords();
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
    const float angle = glm::radians(360.0f / getSampleRate());

    for(unsigned index = 0; index < getSampleRate(); ++index) {
        vertices.push_back(pattern);
        pattern = glm::rotateY(pattern, angle);
    }
}

void CylinderGenerator::connectSides() {
    for(unsigned index = 0; index < getSampleRate(); ++index) {
        const unsigned next = nextIndex(index);

        const IndexGroup firstTriangle{
            index,
            next,
            next + getSampleRate()
        };
        indices.push_back(firstTriangle);

        const IndexGroup secondTriangle{
            index,
            index + getSampleRate(),
            next + getSampleRate()
        };
        indices.push_back(secondTriangle);
    }
}

void CylinderGenerator::createTexCoords() {

    float left = 0;
    float right = 2.0f/getSampleRate();

    for (unsigned index = 0; index < getSampleRate(); ++index) {
        const unsigned next = nextIndex(index);
        vertices[index].texture = glm::vec2(right, 0);
        vertices[index + getSampleRate()].texture = glm::vec2(right, 1);
        vertices[next].texture = glm::vec2(left, 1);
        vertices[next + getSampleRate()].texture = glm::vec2(left, 1);

        right += 2.0f / getSampleRate();
        left += 2.0f / getSampleRate();
    }
}

unsigned CylinderGenerator::nextIndex(unsigned index) const {
    ++index;
    if(index == getSampleRate()) {
        index = 0;
    }
    return index;
}
