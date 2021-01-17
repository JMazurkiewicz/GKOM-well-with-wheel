#include "WellModel.h"

#include <algorithm>
#include <cmath>

WellModel::WellModel():
	basePoint{0.0f, 0.0f, 0.0f},
	innerRadius{DEFAULT_INNER_RADIUS},
	brickWidth{DEFAULT_BRICK_WIDTH},
	brickHeight{DEFAULT_BRICK_HEIGHT},
	layerRotationAngle{DEFAULT_LAYER_ROTATION_ANGLE},
	sideCount{DEFAULT_SIDE_COUNT},
	layerCount{DEFAULT_LAYER_COUNT} { }

glm::vec3 WellModel::getBasePoint() const {
	return basePoint;
}

void WellModel::setBasePoint(const glm::vec3& newBasePoint) {
	basePoint = newBasePoint;
}

float WellModel::getInnerRadius() const noexcept {
	return innerRadius;
}

void WellModel::setInnerRadius(float newInnerRadius) {
	innerRadius = std::clamp(newInnerRadius, INNER_RADIUS_LOWER_BOUND, INNER_RADIUS_UPPER_BOUND);
}

float WellModel::getBrickWidth() const noexcept {
	return brickWidth;
}

void WellModel::setBrickWidth(float newBrickWidth) {
	brickWidth = std::clamp(newBrickWidth, BRICK_WIDTH_LOWER_BOUND, BRICK_WIDTH_UPPER_BOUND);
}

float WellModel::getBrickHeight() const noexcept {
	return brickHeight;
}

void WellModel::setBrickHeight(float newBrickHeight) {
	brickHeight = std::clamp(newBrickHeight, BRICK_HEIGHT_LOWER_BOUND, BRICK_HEIGHT_UPPER_BOUND);
}

float WellModel::getLayerRotationAngle() const noexcept {
	return layerRotationAngle;
}

void WellModel::setLayerRotationAngle(float newLayerRotationAngle) {
	layerRotationAngle = std::fmod(newLayerRotationAngle, 360.0f);
}

unsigned WellModel::getSideCount() const noexcept {
	return sideCount;
}

void WellModel::setSideCount(unsigned newSideCount) {
	sideCount = std::clamp(newSideCount, SIDE_COUNT_LOWER_BOUND, SIDE_COUNT_UPPER_BOUND);
	if(sideCount % 2 == 1) {
		++sideCount;
	}
}

unsigned WellModel::getLayerCount() const noexcept {
	return layerCount;
}

void WellModel::setLayerCount(unsigned newLayerCount) {
	layerCount = std::clamp(newLayerCount, LAYER_COUNT_LOWER_BOUND, LAYER_COUNT_UPPER_BOUND);
}
