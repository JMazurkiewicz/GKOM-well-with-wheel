#pragma once

#include "BrickGlModel.h"
#include <ostream>
#include <vector>

/**
 * @brief OpenGL compatible well model.
 */
class WellGlModel {
public:
	WellGlModel() = default;
	WellGlModel(const WellGlModel&) = delete;
	WellGlModel& operator=(const WellGlModel&) = delete;
	WellGlModel(WellGlModel&&) = default;
	WellGlModel& operator=(WellGlModel&&) = default;

	void addBrick(BrickGlModel&& glModel);

	friend std::ostream& operator<<(std::ostream& stream, const WellGlModel& model);

private:
	friend class WellGlView;
	std::vector<BrickGlModel> bricks;
};
