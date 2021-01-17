#include "BrickGlModelGenerator.h"

#include <cassert>
#include <cmath>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

BrickGlModelGenerator::BrickGlModelGenerator(const WellModel& model)
	: brickHeight(model.getBrickHeight()), brickWidth(model.getBrickWidth()),
	brickLength{calculateBrickLength(model)} { }

void BrickGlModelGenerator::setStart(const glm::vec3& newStart) {
	start = newStart;
}

void BrickGlModelGenerator::setCreator(const glm::vec3& newCreator) {
	creator = newCreator;
}

BrickGlModel BrickGlModelGenerator::generate() {
	adjustCreator();
	make0();
	make1();
	make2();
	make3();
	make4();
	make5();
	make6();
	make7();

	BrickGlModel model;
	model.vertices = vertices;
	return model;
}

float BrickGlModelGenerator::calculateBrickLength(const WellModel& model) {
	const float innerAngle = glm::two_pi<float>() / model.getSideCount();
	return model.getInnerRadius() * std::sqrt(1 - 2*std::cos(innerAngle));
}

void BrickGlModelGenerator::adjustCreator() {
	assert(std::abs(creator.z) < 0.005);

	const float length = glm::length(creator);
	creator *= length / brickWidth;
}

void BrickGlModelGenerator::adjustPerpendicular() {
	const glm::mat3 rot = {
		{0,  1, 0},
		{-1, 0, 0},
		{0,  0, 1}
	};
	perpendicular = creator * rot;

	const float length = glm::length(perpendicular);
	perpendicular *= length / brickLength;
}

void BrickGlModelGenerator::make0() {
	vertices[0] = start;
}

void BrickGlModelGenerator::make1() {
	vertices[1] = vertices[0] + glm::vec3{0, 0, brickHeight};
}

void BrickGlModelGenerator::make2() {
	vertices[2] = vertices[1] + creator;
}

void BrickGlModelGenerator::make3() {
	vertices[3] = start + creator;
}

void BrickGlModelGenerator::make4() {
	vertices[4] = start + perpendicular;
}

void BrickGlModelGenerator::make5() {
	vertices[5] = vertices[4] + glm::vec3{0, 0, brickHeight};
}

void BrickGlModelGenerator::make6() {
	vertices[6] = vertices[5] + creator;
}

void BrickGlModelGenerator::make7() {
	vertices[7] = vertices[4] + creator;
}
