#pragma once

#include "CylinderGenerator.h"

class HollowCylinderGenerator : public CylinderGenerator {
public:
	HollowCylinderGenerator();
	using CylinderGenerator::CylinderGenerator;

	void setInnerRadius(float newInnerRadius);
	void setOuterRadius(float newOuterRadius);

	[[nodiscard]] unsigned getVertexCount() const override;

private:
	using CylinderGenerator::setRadius;

	[[nodiscard]] unsigned getOuterCyilnderOffset() const;
	[[nodiscard]] unsigned getInnerCylinderOffset() const;

	void constructModel() override;
	void adjustInnerIndices(unsigned firstInnerIndex);
	void connectTop();
	unsigned nextIndex(unsigned index) const;

	void createTexCoords() override;

	float innerRadius;
	float outerRadius;
};