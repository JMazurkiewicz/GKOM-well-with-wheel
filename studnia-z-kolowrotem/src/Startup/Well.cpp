#include "Well.h"

#include "ModelGeneration/WellGeneration/SpinningWheelGenerator.h"
#include "ModelGeneration/WellGeneration/WellBaseGenerator.h"
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
}

void Well::create() {
	createBase();
	createWoodenStand();
	createSpinningWheel();
}

void Well::createBase() {
	WellBaseGenerator generator{basicModel};
	generator.setSampleRate(4);
	auto [vertices, indices] = generator.generateModel();
	baseModel = GlModel{std::move(vertices), std::move(indices)};
	baseView.setModel(baseModel);
}

void Well::createWoodenStand() {
	WoodenStandGenerator generator{basicModel};
	generator.setSampleRate(4);
	auto [verticies, indicies] = generator.generateModel();
	woodenStandModel = GlModel{std::move(verticies), std::move(indicies)};
	woodenStandView.setModel(woodenStandModel);
}

void Well::createSpinningWheel() {
	SpinningWheelGenerator generator{basicWheelModel};
	auto [vertices, indices] = generator.generateModel();
	spinningWheelModel = GlModel{std::move(vertices), std::move(indices)};
	spinningWheelView.setModel(spinningWheelModel);
}
