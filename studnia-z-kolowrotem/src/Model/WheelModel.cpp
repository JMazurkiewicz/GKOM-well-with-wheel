#include "WheelModel.h"

float WheelModel::getMiddleElementRadius() const noexcept {
    return middleElementRadius;
}

void WheelModel::setMiddleElementRadius(float newMiddleElementRadius) {
    middleElementRadius = newMiddleElementRadius;
}

float WheelModel::getInnerRadius() const noexcept {
    return innerRadius;
}

void WheelModel::setInnerRadius(float newInnerRadius) {
    innerRadius = newInnerRadius;
}

float WheelModel::getOuterRadius() const noexcept {
    return outerRadius;
}

void WheelModel::setOuterRadius(float newOuterRadius) {
    outerRadius = newOuterRadius;
}

float WheelModel::getHeight() const noexcept {
    return height;
}

void WheelModel::setHeight(float newHeight) {
    height = newHeight;
}

float WheelModel::getConnectorHeight() const noexcept {
    return connectorHeight;
}

void WheelModel::setConnectorHeight(float newConnectorHeight) {
    connectorHeight = newConnectorHeight;
}

unsigned WheelModel::getConnectorCount() const noexcept {
    return connectorCount;
}

void WheelModel::setConnectorCount(unsigned newConnectorCount) {
    connectorCount = newConnectorCount;
}
