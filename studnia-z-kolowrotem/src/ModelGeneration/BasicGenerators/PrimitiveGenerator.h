#pragma once

#include "ModelGenerator.h"

class PrimitiveGenerator : public ModelGenerator {
public:
	PrimitiveGenerator() = default;
	PrimitiveGenerator(const PrimitiveGenerator&) = delete;
	PrimitiveGenerator operator=(const PrimitiveGenerator&) = delete;

	void setColor(const glm::vec3& newColor);

private:
	void finishModel() override;
	virtual void createNormals();
	void doColoring();

	glm::vec3 color;
};
