#pragma once

#include "PrimitiveGenerator.h"

class CuboidGenerator : public PrimitiveGenerator {
public:
	CuboidGenerator();
	CuboidGenerator(const CuboidGenerator&) = delete;
	CuboidGenerator& operator=(const CuboidGenerator&) = delete;

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