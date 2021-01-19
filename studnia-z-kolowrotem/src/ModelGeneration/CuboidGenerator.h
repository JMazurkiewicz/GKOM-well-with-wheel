#pragma once

#include "GeneratorBase.h"

class CuboidGenerator : public GeneratorBase {
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