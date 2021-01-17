#include "WellGlView.h"

#include "Model/WellGlModel.h"
#include <sstream>

WellGlView::WellGlView(const WellGlModel& model) {
	setModel(model);
}

void WellGlView::setModel(const WellGlModel& model) {
	createBrickViews(model);
}

void WellGlView::draw() {
	for(auto& viewPtr : brickViews) {
		viewPtr->draw();
	}
}

void WellGlView::createBrickViews(const WellGlModel& model) {
	brickViews.clear();
	brickViews.reserve(model.bricks.size());

	for(const BrickGlModel& brickModel : model.bricks) {
		brickViews.emplace_back(std::make_unique<BrickGlView>(brickModel));
	}
}

std::ostream& operator<<(std::ostream& stream, const WellGlView& view) {
	stream << "[well-view:" << &view << "]\n";
	for(auto&& brickView : view.brickViews) {
		stream << *brickView;
	}
	return stream;
}
