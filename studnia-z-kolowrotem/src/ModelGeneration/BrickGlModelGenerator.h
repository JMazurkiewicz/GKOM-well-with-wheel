#pragma once

#include "Model/WellModel.h"
#include "Model/BrickGlModel.h"

class BrickGlModelGenerator {
public:
	explicit BrickGlModelGenerator(const WellModel& model);
	BrickGlModelGenerator(const BrickGlModelGenerator&) = delete;
	BrickGlModelGenerator& operator=(const BrickGlModelGenerator&) = delete;

	void setStart(const glm::vec3& newStart);
	void setCreator(const glm::vec3& newCreator);

	[[nodiscard]] BrickGlModel generate();

private:
	static float calculateBrickLength(const WellModel& model);

	void adjustCreator();
	void adjustPerpendicular();

	void make0();
	void make1();
	void make2();
	void make3();
	void make4();
	void make5();
	void make6();
	void make7();

	const float brickHeight;
	const float brickWidth;
	const float brickLength;

	glm::vec3 start;
	glm::vec3 creator;

	glm::vec3 perpendicular;

	BrickGlModel::VertexArray vertices;
};
