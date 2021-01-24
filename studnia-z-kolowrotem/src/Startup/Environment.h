#pragma once

#include "GlModel/GlModel.h"
#include "Model/EnvironmentModel.h"
#include "View/StaticGlView.h"

class Environment {
public:
	Environment();
	Environment(const Environment&) = delete;
	Environment& operator=(const Environment&) = delete;

	void update();

private:
	void create();

	EnvironmentModel basicModel;
	GlModel model;
	StaticGlView view;
};
