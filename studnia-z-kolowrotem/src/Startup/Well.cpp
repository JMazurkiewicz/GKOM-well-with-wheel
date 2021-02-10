#include "Well.h"

#include "ModelGeneration/WellGeneration/WheelGenerator.h"
#include "ModelGeneration/WellGeneration/WellBaseGenerator.h"
#include "ModelGeneration/WellGeneration/WellRoofGenerator.h"
#include "ModelGeneration/WellGeneration/WoodenStandGenerator.h"

Well::Well(Window& window) : wheelControler{basicModel} {
	create();
	wheelControler.listenOn(window);
	stopwatch.reset();
}

void Well::update() {
	const float elapsedTime = stopwatch.getElapsedTime().count();
	wheelControler.update(elapsedTime);

	Texture texture;
	texture.loadTexture("stone2.DDS");
	baseView.draw();
	texture.loadTexture("wood.DDS");
	woodenStandView.draw();
	wheelView.draw();
	texture.loadTexture("plank.DDS");
	roofView.draw();
}

void Well::create() {
	createBase();
	createWoodenStand();
	createWheel();
	createRoof();
}

void Well::createBase() {
	WellBaseGenerator generator{basicModel};
	baseModel = generator.generateModel();
	baseView.setModel(baseModel);
}

void Well::createWoodenStand() {
	WoodenStandGenerator generator{basicModel};
	woodenStandModel = GlModel{generator.generateModel()};
	woodenStandView.setModel(woodenStandModel);
}

void Well::createWheel() {
	WheelGenerator generator{basicModel, basicWheelModel};
	wheelModel = generator.generateModel();
	wheelView.setModel(wheelModel);

	wheelControler.setModel(wheelModel);
	wheelControler.setView(wheelView);
}

void Well::createRoof() {
	WellRoofGenerator generator{basicModel, basicRoofModel};
	generator.setSeed(std::random_device{}());
	roofModel = generator.generateModel();
	roofView.setModel(roofModel);
}
