#pragma once

#include "GlModel/GlModel.h"
#include "Model/RoofModel.h"
#include "Model/WellModel.h"
#include "Model/WheelModel.h"
#include "System/Window.h"
#include "View/GlView.h"

class Well {
public:
	explicit Well(Window& window);
	Well(const Well&) = delete;
	Well& operator=(const Well&) = delete;

	void update();

private:
	void create();
	void createBase();
	void createWoodenStand();
	void createWheel();
	void createRoof();

	WellModel basicModel;
	WheelModel basicWheelModel;
	RoofModel basicRoofModel;

	GlModel woodenStandModel;
	GlView woodenStandView;

	GlModel baseModel;
	GlView baseView;

	GlModel spinningWheelModel;
	GlView spinningWheelView;
	WheelControler wheelControler;

	GlModel roofModel;
	GlView roofView;
};
