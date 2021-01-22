#include "Well.h"

Well::Well() {
	create();
}

void Well::update() {
	baseView.draw();
	woodenStandView.draw();
}

void Well::create() {
	createBase();
	createWoodenStand();
}

void Well::createBase() {
	WellBaseGenerator generator{basicModel};
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
