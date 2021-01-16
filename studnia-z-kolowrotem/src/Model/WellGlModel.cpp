#include "WellGlModel.h"

void WellGlModel::addBrick(BrickGlModel&& glModel) {
	bricks.push_back(std::move(glModel));
}
