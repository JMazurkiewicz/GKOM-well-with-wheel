#pragma once

#include "ModelGenerator.h"

class PrimitiveGenerator : public ModelGenerator {
public:
	using ModelGenerator::ModelGenerator;

	void setColor(const glm::vec3& newColor);

protected:
	virtual void createTexCoords() = 0;

private:
	void finishModel() override;
	void doColoring();

	glm::vec3 color;
};
