#include "Well.h"

Well::Well() {
	create();
}

void Well::update() {
	woodenStandView.draw();
}

void Well::create() {
	createWoodenStand();
}

void Well::createWoodenStand() {
	WoodenStandGenerator generator{basicModel};
	auto [verticies, indicies] = generator.generateModel();
	woodenStandModel = GlModel{std::move(verticies), std::move(indicies)};
	woodenStandView.setModel(woodenStandModel);
}
