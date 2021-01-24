#include "Well.h"

#include "ModelGeneration/WellGeneration/WheelGenerator.h"
#include "ModelGeneration/WellGeneration/WellBaseGenerator.h"
#include "ModelGeneration/WellGeneration/WellRoofGenerator.h"
#include "ModelGeneration/WellGeneration/WoodenStandGenerator.h"

Well::Well(Window& window) {
	create();
	wheelControler.listenOn(window);
	stopwatch.reset();
}

void Well::update() {
	Texture texture;

	texture.loadTexture("abc.DDS");
	const float elapsedTime = stopwatch.getElapsedTime().count();
	
	wheelControler.update(elapsedTime);

	baseView.draw();

	texture.loadTexture("yas.DDS");
	woodenStandView.draw();


	texture.loadTexture("texture.DDS");
	spinningWheelView.draw();
	wheelView.draw();
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
	generator.setSampleRate(64);
	auto [vertices, indices] = generator.generateModel();
	baseModel = GlModel{std::move(vertices), std::move(indices)};
	baseView.setModel(baseModel);
}

void Well::createWoodenStand() {
	WoodenStandGenerator generator{basicModel};
	generator.setSampleRate(64);
	auto [verticies, indicies] = generator.generateModel();
	woodenStandModel = GlModel{std::move(verticies), std::move(indicies)};
	woodenStandView.setModel(woodenStandModel);
}

void Well::createWheel() {
	WheelGenerator generator{basicModel, basicWheelModel};
	auto [vertices, indices] = generator.generateModel();
	wheelModel = GlModel{std::move(vertices), std::move(indices)};
	wheelView.setModel(wheelModel);

	wheelControler.setModel(wheelModel);
	wheelControler.setView(wheelView);
}

void Well::createRoof() {
	WellRoofGenerator generator{basicModel, basicRoofModel};
	auto [vertices, indices] = generator.generateModel();
	roofModel = GlModel{std::move(vertices), std::move(indices)};
	roofView.setModel(roofModel);
}
