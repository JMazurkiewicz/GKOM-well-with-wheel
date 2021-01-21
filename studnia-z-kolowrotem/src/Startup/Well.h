#pragma once

#include "Model/GlModel.h"
#include "Model/WellModel.h"
#include "ModelGeneration/WellGeneration/WoodenStandGenerator.h"
#include "View/GlView.h"

class Well {
public:
	Well();
	Well(const Well&) = delete;
	Well& operator=(const Well&) = delete;

	void update();

private:
	void create();
	void createWoodenStand();

	WellModel basicModel;

	GlModel woodenStandModel;
	GlView woodenStandView;
};
