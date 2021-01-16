#pragma once

#include "Model/WellGlModel.h"
#include "Model/WellModel.h"

class WellGlModelGenerator {
public:
	explicit WellGlModelGenerator(const WellModel& rawModel);
	WellGlModelGenerator(const WellGlModelGenerator&) = delete;
	WellGlModelGenerator& operator=(const WellGlModelGenerator&) = delete;

	[[nodiscard]] WellGlModel generate();

private:
	void generateLayer(unsigned layerIndex);
	void generateOneBrick();

	const WellModel& rawModel;
	WellGlModel glModel;

	float layerAngle;
	glm::vec3 creator;

	// useful constants
	const float innerAngle;
};