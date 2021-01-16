#pragma once

#include <memory>
#include <vector>
#include "View/BrickGlView.h"

class WellGlModel;

class WellGlView {
public:
	WellGlView() = default;
	explicit WellGlView(const WellGlModel& model);
	WellGlView(const WellGlView&) = delete;
	WellGlView& operator=(const WellGlView&) = delete;

	void setModel(const WellGlModel& model);
	void draw();

private:
	void createBrickViews(const WellGlModel& model);
	
	std::vector<std::unique_ptr<BrickGlView>> brickViews;
};
