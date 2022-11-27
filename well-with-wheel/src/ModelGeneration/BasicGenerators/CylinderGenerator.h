#pragma once

#include "SmoothShapeGenerator.h"

class CylinderGenerator : public SmoothShapeGenerator {
public:
    CylinderGenerator() = default;
    using SmoothShapeGenerator::SmoothShapeGenerator;

    void setRadius(float newRadius);
    void setHeight(float newHeight);

    [[nodiscard]] unsigned getVertexCount() const override;

protected:
    [[nodiscard]] unsigned getSampleCount() const;
    [[nodiscard]] unsigned getLowerCircleOffset() const;
    [[nodiscard]] unsigned getUpperCircleOffset() const;

    void createVertices() override;
    void createIndices() override;
    void createTexCoords() override;

private:
    void createLowerCircle();
    void createUpperCircle();
    void createCircle(const glm::vec3& start);

    float radius = 1.0f;
    float height = 1.0f;
};
