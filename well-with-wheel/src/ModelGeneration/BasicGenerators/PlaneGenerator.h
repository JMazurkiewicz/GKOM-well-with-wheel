#pragma once

#include "PrimitiveGenerator.h"

class PlaneGenerator : public PrimitiveGenerator {
public:
	PlaneGenerator() = default;

	void setWidth(float newWidth);
	void setLength(float newLength);

	[[nodiscard]] unsigned getVertexCount() const override;

private:
	void createVertices() override;
	void createIndices() override;
	void createTexCoords() override;

	float width = 1.0f;
	float length = 1.0f;
};
