#include "WellGlModelGenerator.h"

#include <cmath>
#include <glm/ext.hpp>

WellGlModelGenerator::WellGlModelGenerator(const WellModel& rawModel)
	: rawModel{rawModel}, innerAngle{360.0f / rawModel.getSideCount()},
	  brickModelGenerator{rawModel}
{
	prepare();
}

void WellGlModelGenerator::prepare() {
	layerAngle = 0.0f;
	layerIndex = 0;

	layerBasePoint = { };
	creator = { };
	start = { };
}

WellGlModel WellGlModelGenerator::generate() {
	prepare();

	while(layerIndex < rawModel.getLayerCount()) {
		generateNewLayer();

		layerAngle = std::fmod(layerAngle + glm::radians(rawModel.getLayerRotationAngle()), glm::two_pi<float>());
		++layerIndex; 
	}

	return std::move(glModel);
}

void WellGlModelGenerator::generateNewLayer() {
	calculateNewVectors();
	
	for(unsigned brickIndex = 0; brickIndex < rawModel.getSideCount(); ++brickIndex) {
		brickModelGenerator.setCreator(creator);
		brickModelGenerator.setStart(start);
		
		glModel.addBrick(brickModelGenerator.generate());
		rotateVectors();
	}
}

void WellGlModelGenerator::calculateNewVectors() {
	calculateLayerBasePoint();
	calculateStart();
	calculateCreator();
}

void WellGlModelGenerator::calculateLayerBasePoint() {
	const glm::vec3 basePoint = rawModel.getBasePoint();
	layerBasePoint = basePoint + glm::vec3{0, 0, basePoint.z + layerIndex * rawModel.getBrickHeight()};
}

void WellGlModelGenerator::calculateStart() {
	start =
		layerBasePoint +
		rawModel.getInnerRadius() * glm::vec3{std::cos(layerAngle), std::sin(layerAngle), 0};
}

void WellGlModelGenerator::calculateCreator() {
	creator = glm::rotateZ(start - layerBasePoint, innerAngle / 2);
}

void WellGlModelGenerator::rotateVectors() {
	glm::mat4 transformation{1};
	transformation = glm::rotate(transformation, innerAngle, glm::vec3{0, 0, 1});

	rotateStart(transformation);
	rotateCreator(transformation);
}

void WellGlModelGenerator::rotateStart(const glm::mat4& transformation) {
	start = glm::vec3{transformation * glm::vec4{start, 1.0f}};
}

void WellGlModelGenerator::rotateCreator(const glm::mat4& transformation) {
	creator = glm::vec3{transformation * glm::vec4{start, 1.0f}};
}
