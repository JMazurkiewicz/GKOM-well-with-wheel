#include "WellModel.h"

#include <stdexcept>

WellModel::WellModel():
	innerRadius{DEFAULT_INNER_RADIUS},
	outerRadius{DEFAULT_OUTER_RADIUS},
	height{DEFAULT_HEIGHT} { }

float WellModel::getInnerRadius() const noexcept {
	return innerRadius;
}

void WellModel::setInnerRadius(float newInnerRadius) {
	innerRadius = newInnerRadius;
}

float WellModel::getOuterRadius() const noexcept {
	return outerRadius;
}

void WellModel::setOuterRadius(float newOuterRadius) {
	outerRadius = newOuterRadius;
}

float WellModel::getHeight() const noexcept {
	return height;
}

void WellModel::setHeight(float newHeight) {
	height = newHeight;
}

void WellModel::validateModel() const {
	if(outerRadius <= innerRadius) {
		throw std::invalid_argument{"WellModel: outerRadius <= innerRadius"};
	}
}


