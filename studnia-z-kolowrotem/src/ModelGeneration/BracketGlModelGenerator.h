#pragma once

#include "Model/WellGlModel.h"
#include "Model/WellModel.h"
#include <utility>

class BracketGlModelGeneator {
public:
	using Vertices = WellGlModel::Vertices;
	using Indices = WellGlModel::Indices;
	using ModelPair = std::pair<Vertices, Indices>;

	static constexpr unsigned DEFAULT_SAMPLE_RATE = 64;
	static constexpr unsigned INVALID_MODEL_OFFSET = -1;

	explicit BracketGlModelGeneator(const WellModel& model);
	BracketGlModelGeneator(const BracketGlModelGeneator&) = delete;
	BracketGlModelGeneator& operator=(const BracketGlModelGeneator&) = delete;

	void setSampleRate(unsigned newSampleRate);
	void setModelOffset(unsigned newModelOffset);
	void setFinalTranslationVector(const glm::vec3& newTranslation);

	[[nodiscard]] unsigned getModelOffset() const;
	[[nodiscard]] ModelPair generate();

private:
	void setupVariables();

	void createVertices();
	void createLowerVertices();
	void createHigherVertices();
	void createCircleFrom(const glm::vec3& start);
	
	void connectVertices();
	unsigned nextIndex(unsigned index);

	void adjustModelOffset();
	void translateModel();

	const WellModel& basicModel;

	unsigned sampleRate;
	unsigned modelOffset;
	glm::vec3 translation;
	Vertices vertices;
	Indices indices;

	float innerAngle;
	unsigned lowerOffset;
	unsigned higherOffset;
};