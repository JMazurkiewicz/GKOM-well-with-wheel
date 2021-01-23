#include "Well.h"

#include "ModelGeneration/WellGeneration/SpinningWheelGenerator.h"
#include "ModelGeneration/WellGeneration/WellBaseGenerator.h"
#include "ModelGeneration/WellGeneration/WellRoofGenerator.h"
#include "ModelGeneration/WellGeneration/WoodenStandGenerator.h"

Well::Well() {
	create();
}

void Well::update() {
	Texture texture;

	texture.loadTexture("abc.DDS");
	baseView.draw();

	texture.loadTexture("yas.DDS");
	woodenStandView.draw();


	texture.loadTexture("texture.DDS");
	spinningWheelView.draw();
	roofView.draw();
}

void Well::create() {
	createBase();
	createWoodenStand();
	createSpinningWheel();
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
	auto [verticies, indicies] = generator.generateModel();
	woodenStandModel = GlModel{std::move(verticies), std::move(indicies)};
	woodenStandView.setModel(woodenStandModel);
}

void Well::createSpinningWheel() {
	SpinningWheelGenerator generator{basicModel, basicWheelModel};
	auto [vertices, indices] = generator.generateModel();
	spinningWheelModel = GlModel{std::move(vertices), std::move(indices)};
	spinningWheelView.setModel(spinningWheelModel);
}

void Well::createRoof() {
	WellRoofGenerator generator{basicModel, basicRoofModel};
	auto [vertices, indices] = generator.generateModel();
	roofModel = GlModel{std::move(vertices), std::move(indices)};
	roofView.setModel(roofModel);
}
