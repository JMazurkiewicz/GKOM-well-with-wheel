#include "WellGlModelGenerator.h"

#include <cmath>
#include <glm/ext.hpp>
#include <iostream>

WellGlModelGenerator::WellGlModelGenerator(const WellModel& basicModel)
	: basicModel{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} { }

void WellGlModelGenerator::setSampleRate(unsigned newSampleRate) {
	sampleRate = newSampleRate;
}

WellGlModel WellGlModelGenerator::generate() {
	basicModel.validateModel();
	setupVariables();
	createVertices();
	return WellGlModel{std::move(vertices), std::move(indices)};
}

void WellGlModelGenerator::setupVariables() {
	innerAngle = glm::radians(360.0f / sampleRate);
	lowerInnerOffset = 0;
	lowerOuterOffset = sampleRate;
	higherInnerOffset = sampleRate * 2;
	higherOuterOffset = sampleRate * 3;
}

void WellGlModelGenerator::createVertices() {
	createLowerInnerVertices();
	createLowerOuterVertices();
	createHigherInnerVertices();
	createHigherOuterVertices();
	connectOuterVertices();
	connectInnerVertices();
	//connectTopVertices();
}

void WellGlModelGenerator::createLowerInnerVertices() {
	glm::vec3 start{basicModel.getInnerRadius(), 0.0f, 0.0f};
	createCircleFrom(start);
}

void WellGlModelGenerator::createLowerOuterVertices() {
	glm::vec3 start{basicModel.getOuterRadius(), 0.0f, 0.0f};
	createCircleFrom(start);
}

void WellGlModelGenerator::createHigherInnerVertices() {
	glm::vec3 start{basicModel.getInnerRadius(), 0.0f, basicModel.getHeight()};
	createCircleFrom(start);
}

void WellGlModelGenerator::createHigherOuterVertices() {
	glm::vec3 start{basicModel.getOuterRadius(), 0.0f, basicModel.getHeight()};
}

void WellGlModelGenerator::createCircleFrom(const glm::vec3& start) {
	glm::vec3 pattern  = start;
	for(unsigned i = 0; i < sampleRate; ++i) {
		vertices.push_back(pattern);
		pattern = glm::rotateZ(pattern, innerAngle);
	}
}

void WellGlModelGenerator::connectOuterVertices() {
	for(unsigned index = 0; index < sampleRate; ++index) {
		const unsigned next = nextIndex(index);
		
		indices.push_back(index + lowerInnerOffset);
		indices.push_back(next + lowerInnerOffset);
		indices.push_back(next + higherInnerOffset);
	
		indices.push_back(index + lowerInnerOffset);
		indices.push_back(index + higherInnerOffset);
		indices.push_back(next + higherInnerOffset);
	}
}

void WellGlModelGenerator::connectInnerVertices() {
	for(unsigned index = 0; index < sampleRate; ++index) {
		const unsigned next = nextIndex(index);

		indices.push_back(index + lowerOuterOffset);
		indices.push_back(next + lowerOuterOffset);
		indices.push_back(next + higherOuterOffset);

		indices.push_back(index + lowerOuterOffset);
		indices.push_back(index + higherOuterOffset);
		indices.push_back(next + higherOuterOffset);
	}
}

void WellGlModelGenerator::connectTopVertices() {
	for(unsigned index = 0; index < sampleRate; ++index) {
		const unsigned next = nextIndex(index);

		indices.push_back(index + higherInnerOffset);
		indices.push_back(index + higherOuterOffset);
		indices.push_back(next + higherOuterOffset);

		indices.push_back(index + higherInnerOffset);
		indices.push_back(next + higherInnerOffset);
		indices.push_back(next + higherOuterOffset);
	}
}

unsigned WellGlModelGenerator::nextIndex(unsigned index) const {
	++index;
	if(index % sampleRate == 0) {
		index = 0;
	}
	return index;
}
