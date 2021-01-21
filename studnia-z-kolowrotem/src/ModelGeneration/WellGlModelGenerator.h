#pragma once

#include "BasicGenerators/CompoundModelGenerator.h"
#include "BasicGenerators/CuboidGenerator.h"
#include "BasicGenerators/CylinderGenerator.h"
#include "BasicGenerators/HollowCylinderGenerator.h"
#include "Model/WellGlModel.h"
#include "Model/WellModel.h"

/**
 * @brief Class used to generate well OpenGl model from basic model.
 */
class WellGlModelGenerator final : protected CompoundModelGenerator {
public:
	static constexpr unsigned DEFAULT_SAMPLE_RATE = 64;

	explicit WellGlModelGenerator(const WellModel& basicModel);
	WellGlModelGenerator(const WellGlModelGenerator&) = delete;
	WellGlModelGenerator& operator=(const WellGlModelGenerator&) = delete;

	void setSampleRate(unsigned newSampleRate);

	[[nodiscard]] WellGlModel generate();

private:
	void prepareGenerators();
	void prepareWellBaseGenerator();
	void prepareLeftBracketGenerator();
	void prepareRightBracketGenerator();
	void prepareLog();

	const WellModel& basicModel;

	HollowCylinderGenerator wellBaseGenerator;
	CylinderGenerator leftBracketGenerator;
	CylinderGenerator rightBracketGenerator;
	CuboidGenerator logGenerator;

	unsigned sampleRate;
};
