#pragma once

#include "BrickGlModel.h"
#include <vector>

class WellGlModel {
public:
	WellGlModel() = default;
	WellGlModel(const WellGlModel&) = delete;
	WellGlModel& operator=(const WellGlModel&) = delete;
	WellGlModel(WellGlModel&&) = default;
	WellGlModel& operator=(WellGlModel&&) = default;

	void addBrick(BrickGlModel&& glModel);

private:
	friend class WellGlView;
	std::vector<BrickGlModel> bricks;
};
