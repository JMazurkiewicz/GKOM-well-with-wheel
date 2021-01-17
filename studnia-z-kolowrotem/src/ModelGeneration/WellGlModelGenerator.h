#pragma once

#include "BrickGlModelGenerator.h"
#include "Model/WellGlModel.h"
#include "Model/WellModel.h"

/**
 * @brief Class used to generate OpenGl model from raw model.
 */
class WellGlModelGenerator {
public:
	explicit WellGlModelGenerator(const WellModel& rawModel);
	WellGlModelGenerator(const WellGlModelGenerator&) = delete;
	WellGlModelGenerator& operator=(const WellGlModelGenerator&) = delete;

	[[nodiscard]] WellGlModel generate();

private:
	void prepare();

	void generateNewLayer();

	void calculateNewVectors();
	void calculateLayerBasePoint();
	void calculateStart();
	void calculateCreator();
	 
	void rotateVectors();
	void rotateStart(const glm::mat4& transformation);
	void rotateCreator(const glm::mat4& transformation);

	const WellModel& rawModel;
	const float innerAngle;

	WellGlModel glModel;

	float layerAngle;
	unsigned layerIndex;

	glm::vec3 layerBasePoint;
	glm::vec3 creator;
	glm::vec3 start;

	BrickGlModelGenerator brickModelGenerator;
};
