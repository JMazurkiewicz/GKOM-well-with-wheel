#pragma once

#include "CylinderGenerator.h"

class HollowCylinderGenerator : public CylinderGenerator {
public:
	HollowCylinderGenerator() = default;
	using CylinderGenerator::CylinderGenerator;

	void setInnerRadius(float newInnerRadius);
	void setOuterRadius(float newOuterRadius);

	[[nodiscard]] unsigned getVertexCount() const override;

private:
	using CylinderGenerator::setRadius;

	[[nodiscard]] unsigned getOuterCyilnderOffset() const;
	[[nodiscard]] unsigned getInnerCylinderOffset() const;

	void createVertices() override;

	void createIndices() override;
	void adjustInnerIndices();
	void connectTop();

	void createTexCoords() override;

	float innerRadius = 1.0f;
	float outerRadius = 1.0f;
};