#pragma once

#include "PrimitiveGenerator.h"

class PlaneGenerator : public PrimitiveGenerator {
public:
	PlaneGenerator();

	void setWidth(float newWidth);
	void setLength(float newLength);

	[[nodiscard]] unsigned getVertexCount() const override;

private:
	void constructModel() override;
	void createTexCoords() override;

	float width;
	float length;
};
