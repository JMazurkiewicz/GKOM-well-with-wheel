#include "CuboidGenerator.h"

void CuboidGenerator::setWidth(float newWidth) {
    width = newWidth;
}

void CuboidGenerator::setHeight(float newHeight) {
    height = newHeight;
}

void CuboidGenerator::setLength(float newLength) {
    length = newLength;
}

unsigned CuboidGenerator::getVertexCount() const {
    return 24;
}

void CuboidGenerator::createVertices() {
    const float halfX = width / 2.0f;
    const float halfZ = length / 2.0f;

    vertices = {
        {+halfX,   0.0f, -halfZ},
        {-halfX,   0.0f, -halfZ},
        {-halfX,   0.0f, +halfZ},
        {+halfX,   0.0f, +halfZ},

        {+halfX, height, -halfZ},
        {-halfX, height, -halfZ},
        {-halfX, height, +halfZ},
        {+halfX, height, +halfZ},

        {-halfX, height, -halfZ},
        {-halfX,   0.0f, -halfZ},
        {-halfX,   0.0f, +halfZ},
        {-halfX, height,  halfZ},

        {+halfX,   0.0f, -halfZ},
        {+halfX, height, -halfZ},
        {+halfX, height, +halfZ},
        {+halfX,   0.0f, +halfZ},

        {+halfX, height, +halfZ},
        {-halfX, height, +halfZ},
        {-halfX,   0.0f, +halfZ},
        {+halfX,   0.0f, +halfZ},

        {-halfX, height, -halfZ},
        {+halfX, height, -halfZ},
        {+halfX,   0.0f, -halfZ},
        {-halfX,   0.0f, -halfZ}
    };
}

void CuboidGenerator::createIndices() {
    for(unsigned sideIndex = 0; sideIndex < 6; ++sideIndex) {
        const unsigned index1 = 4 * sideIndex;
        const unsigned index2 = index1 + 1;
        const unsigned index3 = index1 + 2;
        const unsigned index4 = index1 + 3;

        indices.push_back({index1, index2, index3});
        indices.push_back({index1, index4, index3});
    }
}

void CuboidGenerator::createTexCoords() {
    for(unsigned sideIndex = 0; sideIndex < 6; ++sideIndex) {
        const unsigned baseIndex = 4 * sideIndex;

        vertices[baseIndex + 0].texture = {1, 1};
        vertices[baseIndex + 1].texture = {0, 1};
        vertices[baseIndex + 2].texture = {0, 0};
        vertices[baseIndex + 3].texture = {1, 0};
    }
}
