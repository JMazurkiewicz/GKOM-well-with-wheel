#pragma once

#include "Model/EnvironmentModel.h"
#include "Model/GlModel.h"
#include "ModelGeneration/EnvironmentGlModelGenerator.h"
#include "View/GlView.h"

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
	GlView view;
};
