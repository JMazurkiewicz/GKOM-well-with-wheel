#pragma once

#include "CompoundModelGenerator.h"
#include "CuboidGenerator.h"
#include "CylinderGenerator.h"
#include "Model/WellGlModel.h"
#include "Model/WellModel.h"

/**
 * @brief Class used to generate well OpenGl model from basic model.
 */
class WellGlModelGenerator final {
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
	void calculateNormals(unsigned index1, unsigned index2, unsigned index3);

	void connectOuterVertices();
	void connectInnerVertices();
	void connectTopVertices();
	unsigned nextIndex(unsigned index) const;

	void prepareLeftBracketGenerator();
	void prepareRightBracketGenerator();
	void prepareLog();

	const WellModel& basicModel;
	CompoundModelGenerator compoundGenerator;

	CylinderGenerator leftBracketGenerator;
	CylinderGenerator rightBracketGenerator;
	CuboidGenerator logGenerator;

	unsigned sampleRate;
	ModelGenerator::Vertices vertices;
	ModelGenerator::Indices indices;

	float innerAngle;
	unsigned lowerInnerOffset;
	unsigned lowerOuterOffset;
	unsigned higherInnerOffset;
	unsigned higherOuterOffset;

	unsigned leftBracketOffset;
	unsigned rightBracketOffset;
	unsigned logOffset;
};
