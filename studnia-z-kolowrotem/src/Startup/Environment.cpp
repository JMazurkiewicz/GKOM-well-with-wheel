#include "Environment.h"

#include "ModelGeneration/EnvironmentGeneration/EnvironmentGenerator.h"

Environment::Environment() {
	create();
}

void Environment::update() {
	Texture texture;
	texture.loadTexture("grass.DDS");
	view.draw();
}

void Environment::create() {
	EnvironmentGenerator generator{basicModel};
	auto [vertices, indices] = generator.generateModel();
	model = GlModel{std::move(vertices), std::move(indices)};
	view.setModel(model);
}
