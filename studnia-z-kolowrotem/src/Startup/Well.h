#pragma once

#include "Model/GlModel.h"
#include "Model/WellModel.h"
#include "Model/WheelModel.h"
#include "View/GlView.h"

class Well {
public:
	Well();
	Well(const Well&) = delete;
	Well& operator=(const Well&) = delete;

	void update();

private:
	void create();
	void createBase();
	void createWoodenStand();
	void createSpinningWheel();

	WellModel basicModel;
	WheelModel basicWheelModel;

	GlModel woodenStandModel;
	GlView woodenStandView;

	GlModel baseModel;
	GlView baseView;

	GlModel spinningWheelModel;
	GlView spinningWheelView;
};
