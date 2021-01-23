#pragma once

#include "Model/GlModel.h"
#include "Model/RoofModel.h"
#include "Model/WellModel.h"
#include "Model/WheelModel.h"
#include "View/GlView.h"
#include "Graphics/Texture.h"

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

	GlModel roofModel;
	GlView roofView;
};
