#pragma once

#include "SmoothShapeGenerator.h"

class CylinderGenerator : public SmoothShapeGenerator {
public:
	CylinderGenerator();
	CylinderGenerator(const CylinderGenerator&) = delete;
	CylinderGenerator& operator=(const CylinderGenerator&) = delete;

	void setRadius(float newRadius);
	void setHeight(float newHeight);

	[[nodiscard]] unsigned getLowerCircleOffset() const;
	[[nodiscard]] unsigned getUpperCircleOffset() const;

	[[nodiscard]] unsigned getVertexCount() const override;

protected:
	void constructModel() override;

private:
	void createLowerCircle();
	void createUpperCircle();
	void createCircle(const glm::vec3& start);

	void connectSides();
	void createTexCoords();
	unsigned nextIndex(unsigned index) const;

	float radius;
	float height;
};
