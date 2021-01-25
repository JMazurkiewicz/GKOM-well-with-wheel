#include "Environment.h"

#include "ModelGeneration/BasicGenerators/CylinderGenerator.h"
#include "ModelGeneration/BasicGenerators/PlaneGenerator.h"

Environment::Environment() {
	create();
}

void Environment::update() {
	Texture texture;
	texture.loadTexture("grass.DDS");
	grassView.draw();
	texture.loadTexture("sky.DDS");
	landscapeView.draw();
}

void Environment::create() {
	createGrass();
	createLandscape();
}

void Environment::createGrass() {
	PlaneGenerator grassGenerator;
	grassGenerator.setLength(basicModel.getSize());
	grassGenerator.setWidth(basicModel.getSize());
	auto [vertices, indices] = grassGenerator.generateModel();
	grassModel = GlModel{std::move(vertices), std::move(indices)};
	grassView.setModel(grassModel);
}

void Environment::createLandscape() {
	CylinderGenerator landscapeGenerator;
	landscapeGenerator.setHeight(basicModel.getHeight());
	landscapeGenerator.setRadius(basicModel.getSize() / 2.0f);
	auto [vertices, indices] = landscapeGenerator.generateModel();
	landscapeModel = GlModel{std::move(vertices), std::move(indices)};
	landscapeView.setModel(landscapeModel);
}
