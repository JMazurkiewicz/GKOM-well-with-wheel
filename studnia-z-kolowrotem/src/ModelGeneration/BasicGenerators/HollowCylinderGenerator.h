#pragma once

#include "CylinderGenerator.h"

class HollowCylinderGenerator : public CylinderGenerator {
public:
	HollowCylinderGenerator();
	HollowCylinderGenerator(const HollowCylinderGenerator&) = delete;
	HollowCylinderGenerator& operator=(const HollowCylinderGenerator&) = delete;

	void setInnerRadius(float newInnerRadius);
	void setOuterRadius(float newOuterRadius);

	[[nodiscard]] unsigned getVertexCount() const override;

private:
	using CylinderGenerator::setRadius;

	[[nodiscard]] unsigned getOuterCyilnderOffset() const;
	[[nodiscard]] unsigned getInnerCylinderOffset() const;

	void constructModel() override;
	void adjustInnerIndices();
	void connectTop();
	unsigned nextIndex(unsigned index) const;

	float innerRadius;
	float outerRadius;
};