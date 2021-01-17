#include "WellGlModel.h"

void WellGlModel::addBrick(BrickGlModel&& glModel) {
	bricks.push_back(std::move(glModel));
}

std::ostream& operator<<(std::ostream& stream, const WellGlModel& model) {
	stream << "[well-model:" << &model << "]:\n";
	for(const BrickGlModel& brick : model.bricks) {
		stream << brick;
	}
	return stream;
}
