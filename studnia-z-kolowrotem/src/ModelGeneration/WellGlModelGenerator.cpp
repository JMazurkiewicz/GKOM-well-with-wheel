#include "WellGlModelGenerator.h"

#include <cmath>
#include <glm/ext.hpp>

WellGlModelGenerator::WellGlModelGenerator(const WellModel& basicModel)
	: basicModel{basicModel}, bracketGenerator{basicModel}, sampleRate{DEFAULT_SAMPLE_RATE} {
	setupVariables();
}

void WellGlModelGenerator::setSampleRate(unsigned newSampleRate) {
	sampleRate = newSampleRate;
}

WellGlModel WellGlModelGenerator::generate() {
	basicModel.validateModel();
	setupVariables();
	createVertices();
	return WellGlModel{std::move(vertices), std::move(indices), std::move(normals)};
}

void WellGlModelGenerator::setupVariables() {
	bracketGenerator.setSampleRate(sampleRate);

	innerAngle = glm::radians(360.0f / sampleRate);
	lowerInnerOffset = 0;
	lowerOuterOffset = lowerInnerOffset + sampleRate;
	higherInnerOffset = lowerOuterOffset + sampleRate;
	higherOuterOffset = higherInnerOffset + sampleRate;

	leftBracketOffset = higherOuterOffset + sampleRate;
	rightBracketOffset = leftBracketOffset + bracketGenerator.getModelOffset();
}

void WellGlModelGenerator::createVertices() {
	createLowerInnerVertices();
	createLowerOuterVertices();
	createHigherInnerVertices();
	createHigherOuterVertices();
	connectOuterVertices();
	connectInnerVertices();
	connectTopVertices();
	createBrackets();
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
	glm::vec3 start{basicModel.getInnerRadius(), basicModel.getHeight(), 0.0f};
	createCircleFrom(start);
}

void WellGlModelGenerator::createHigherOuterVertices() {
	glm::vec3 start{basicModel.getOuterRadius(), basicModel.getHeight(), 0.0f};
	createCircleFrom(start);
}

void WellGlModelGenerator::createCircleFrom(const glm::vec3& start) {
	glm::vec3 pattern  = start;
	for(unsigned i = 0; i < sampleRate; ++i) {
		vertices.push_back(pattern);
		pattern = glm::rotateY(pattern, innerAngle);
	}
}

void WellGlModelGenerator::calculateNormals(unsigned index1, unsigned index2, unsigned index3) {
	glm::vec3 edge1;
	glm::vec3 edge2;

	edge1 = vertices[index2] - vertices[index1];
	edge2 = vertices[index3] - vertices[index1];


	normals.push_back(glm::normalize(glm::cross(edge1, edge2)));
}

void WellGlModelGenerator::connectOuterVertices() {
	for(unsigned index = 0; index < sampleRate; ++index) {
		const unsigned next = nextIndex(index);
		
		indices.push_back(index + lowerInnerOffset);
		indices.push_back(next + higherInnerOffset);
		indices.push_back(next + lowerInnerOffset);

		calculateNormals(index + lowerInnerOffset, next + higherInnerOffset, next + lowerInnerOffset);
	
		indices.push_back(index + lowerInnerOffset);
		indices.push_back(next + higherInnerOffset);
		indices.push_back(index + higherInnerOffset);

		calculateNormals(index + lowerInnerOffset, next + higherInnerOffset, index + higherInnerOffset);
	}
}

void WellGlModelGenerator::connectInnerVertices() {

	bool tryOnce = true;
	for(unsigned index = 0; index < sampleRate; ++index) {
		const unsigned next = nextIndex(index);

		

		indices.push_back(index + lowerOuterOffset);
		indices.push_back(next + higherOuterOffset);
		indices.push_back(next + lowerOuterOffset);

		calculateNormals(index + lowerOuterOffset, next + higherOuterOffset, next + lowerOuterOffset);

		/*if (tryOnce) {
			std::cout << vertices[index + lowerOuterOffset].x << "  " << vertices[index + lowerOuterOffset].y << "  " << vertices[index + lowerOuterOffset].z << std::endl;

			std::cout << vertices[next + higherOuterOffset].x << "  " << vertices[next + higherOuterOffset].y << "  " << vertices[next + higherOuterOffset].z << std::endl;

			std::cout << vertices[next + lowerOuterOffset].x << "  " << vertices[next + lowerOuterOffset].y << "  " << vertices[next + lowerOuterOffset].z << std::endl;

			

			std::cout << edge1.x << "  " << edge1.y << "  " << edge1.z << std::endl;

			std::cout << edge2.x << "  " << edge2.y << "  " << edge2.z << std::endl;

			normals.push_back(glm::normalize(glm::cross(edge1, edge2)));

			std::cout << normals[0].x << "  " << normals[0].y << "  " << normals[0].z << std::endl;

			tryOnce = false;
		}*/

		indices.push_back(index + lowerOuterOffset);
		indices.push_back(next + higherOuterOffset);
		indices.push_back(index + higherOuterOffset);

		calculateNormals(index + lowerOuterOffset, next + higherOuterOffset, index + higherOuterOffset);
	}
}

void WellGlModelGenerator::connectTopVertices() {
	for(unsigned index = 0; index < sampleRate; ++index) {
		const unsigned next = nextIndex(index);

		indices.push_back(index + higherInnerOffset);
		indices.push_back(index + higherOuterOffset);
		indices.push_back(next + higherOuterOffset);

		calculateNormals(index + higherInnerOffset, index + higherOuterOffset, next + higherOuterOffset);

		indices.push_back(index + higherInnerOffset);
		indices.push_back(next + higherInnerOffset);
		indices.push_back(next + higherOuterOffset);

		calculateNormals(index + higherInnerOffset, next + higherInnerOffset, next + higherOuterOffset);
	}
}

unsigned WellGlModelGenerator::nextIndex(unsigned index) const {
	++index;
	if(index == sampleRate) {
		index = 0;
	}
	return index;
}


void WellGlModelGenerator::createBrackets() {
	const glm::vec3 translation{
		basicModel.getInnerRadius() - basicModel.getBracketRadius() / 2.0,
		0.0f, 0.0
	};
	createBracketModel(-translation, leftBracketOffset);
	createBracketModel(translation, rightBracketOffset);
}

void WellGlModelGenerator::createBracketModel(const glm::vec3& translation, unsigned modelOffset) {
	bracketGenerator.setModelOffset(modelOffset);
	bracketGenerator.setFinalTranslationVector(translation);

	auto [newVertices, newIndices] = bracketGenerator.generate();

	vertices.insert(vertices.end(), newVertices.begin(), newVertices.end());
	indices.insert(indices.end(), newIndices.begin(), newIndices.end());
}
