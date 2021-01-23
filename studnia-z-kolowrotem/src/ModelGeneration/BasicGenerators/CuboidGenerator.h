#pragma once

#include "PrimitiveGenerator.h"

class CuboidGenerator : public PrimitiveGenerator {
public:
	CuboidGenerator();
	using PrimitiveGenerator::PrimitiveGenerator;

	void setLength(float newLength);
	void setWidth(float newWidth);
	void setHeight(float newHeight);

	[[nodiscard]] unsigned getVertexCount() const override;

private:
	void constructModel() override;

	void constructVertices();
	void connectVertices();

	float length;
	float width;
	float height;
};