#pragma once

#include "SmoothShapeGenerator.h"

class CylinderGenerator : public SmoothShapeGenerator {
public:
	CylinderGenerator();
	using SmoothShapeGenerator::SmoothShapeGenerator;

	void setRadius(float newRadius);
	void setHeight(float newHeight);

	[[nodiscard]] unsigned getVertexCount() const override;

protected:
	[[nodiscard]] unsigned getSampleCount() const;
	[[nodiscard]] unsigned getLowerCircleOffset() const;
	[[nodiscard]] unsigned getUpperCircleOffset() const;

	void constructModel() override;

private:
	void createLowerCircle();
	void createUpperCircle();
	void createCircle(const glm::vec3& start);

	void connectSides();
	void createTexCoords() override;

	float radius;
	float height;
};
