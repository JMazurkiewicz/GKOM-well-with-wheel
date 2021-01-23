#include "Well.h"

#include "ModelGeneration/WellGeneration/SpinningWheelGenerator.h"
#include "ModelGeneration/WellGeneration/WellBaseGenerator.h"
#include "ModelGeneration/WellGeneration/WoodenStandGenerator.h"

Well::Well() {
	create();
}

void Well::update() {
	baseView.draw();
	woodenStandView.draw();
	spinningWheelView.draw();
}

void Well::create() {
	createBase();
	createWoodenStand();
	createSpinningWheel();
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
