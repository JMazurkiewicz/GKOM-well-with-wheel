#pragma once

#include "BracketGlModelGenerator.h"
#include "Model/WellGlModel.h"
#include "Model/WellModel.h"

/**
 * @brief Class used to generate well OpenGl model from basic model.
 */
class WellGlModelGenerator {
public:
	using Vertices = WellGlModel::Vertices;
	using Indices = WellGlModel::Indices;

	static constexpr unsigned DEFAULT_SAMPLE_RATE = 64;

	explicit WellGlModelGenerator(const WellModel& basicModel);
	WellGlModelGenerator(const WellGlModelGenerator&) = delete;
	WellGlModelGenerator& operator=(const WellGlModelGenerator&) = delete;

	void setSampleRate(unsigned newSampleRate);

	[[nodiscard]] WellGlModel generate();

private:
	void setupVariables();

	void createVertices();
	void createLowerInnerVertices();
	void createLowerOuterVertices();
	void createHigherInnerVertices();
	void createHigherOuterVertices();
	void createCircleFrom(const glm::vec3& start);

	void connectOuterVertices();
	void connectInnerVertices();
	void connectTopVertices();
	unsigned nextIndex(unsigned index) const;

	void createBrackets();
	void createBracketModel(const glm::vec3& translation, unsigned modelOffset);

	const WellModel& basicModel;
	BracketGlModelGeneator bracketGenerator;

	unsigned sampleRate;
	Vertices vertices;
	Indices indices;

	float innerAngle;
	unsigned lowerInnerOffset;
	unsigned lowerOuterOffset;
	unsigned higherInnerOffset;
	unsigned higherOuterOffset;

	unsigned leftBracketOffset;
	unsigned rightBracketOffset;
};
