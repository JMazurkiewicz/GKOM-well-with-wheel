#include "Environment.h"

Environment::Environment() {
	create();
}

void Environment::update() {
	view.draw();
}

void Environment::create() {
	EnvironmentGlModelGenerator generator{basicModel};
	model = generator.generate();
	view.setModel(model);
}
