#include "Environment.h"

Environment::Environment() {
	create();
}

void Environment::update() {
	Texture texture;
	texture.loadTexture("grass.DDS");
	view.draw();
}

void Environment::create() {
	EnvironmentGlModelGenerator generator{basicModel};
	model = generator.generate();
	view.setModel(model);
}
