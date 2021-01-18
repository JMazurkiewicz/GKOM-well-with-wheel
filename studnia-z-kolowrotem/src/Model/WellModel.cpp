#include "WellModel.h"

#include <stdexcept>

WellModel::WellModel():
	innerRadius{DEFAULT_INNER_RADIUS},
	outerRadius{DEFAULT_OUTER_RADIUS},
	height{DEFAULT_HEIGHT},
	bracketRadius{DEFAULT_BRACKET_RADIUS},
	bracketHeight{DEFAULT_BRACKET_HEIGHT} { }

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
	if(newHeight <= 0.0f) {
		throw std::invalid_argument{"WellModel: newHeight <= 0"};
	} else {
		height = newHeight;
	}
}

float WellModel::getBracketRadius() const noexcept {
	return bracketRadius;
}

void WellModel::setBracketRadius(float newBracketRadius) {
	if(newBracketRadius <= 0.0f) {
		throw std::invalid_argument{"WellModel: bracketRadius <= 0"};
	} else {
		bracketRadius = newBracketRadius;
	}
}

float WellModel::getBracketHeight() const noexcept {
	return bracketHeight;
}

void WellModel::setBrackedHeight(float newBracketHeight) {
	bracketHeight = newBracketHeight;
}

void WellModel::validateModel() const {
	if(outerRadius <= innerRadius) {
		throw std::invalid_argument{"WellModel: outerRadius <= innerRadius"};
	}

}


