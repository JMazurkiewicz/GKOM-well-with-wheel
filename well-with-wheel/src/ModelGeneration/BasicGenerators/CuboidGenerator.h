#pragma once

#include "PrimitiveGenerator.h"

class CuboidGenerator : public PrimitiveGenerator {
public:
    CuboidGenerator() = default;
    using PrimitiveGenerator::PrimitiveGenerator;

    void setWidth(float newWidth);
    void setHeight(float newHeight);
    void setLength(float newLength);

    [[nodiscard]] unsigned getVertexCount() const override;

private:
    void createVertices() override;
    void createTexCoords() override;
    void createIndices() override;

    float length = 1.0f;
    float width = 1.0f;
    float height = 1.0f;
};