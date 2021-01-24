#pragma once

#include <stdexcept>
#include <string_view>

class WheelModel {
public:
	static constexpr float DEFAULT_MIDDLE_ELEMENT_RADIUS = 0.02f;
	static constexpr float DEFAULT_INNER_RADIUS = 0.17f;
	static constexpr float DEFAULT_OUTER_RADIUS = 0.15f;
	static constexpr float DEFAULT_HEIGHT = 0.05f;
	static constexpr float DEFAULT_CONNECTOR_HEIGHT = 0.02;

	static constexpr unsigned DEFAULT_CONNECTOR_COUNT = 8;

	constexpr WheelModel() = default;
	WheelModel(const WheelModel&) = delete;
	WheelModel& operator=(const WheelModel&) = delete;

	constexpr float getMiddleElementRadius() const noexcept {
		return middleElementRadius;
	}

	constexpr void setMiddleElementRadius(float newMiddleElementRadius) {
		throwIfNegative(newMiddleElementRadius, "middle element radius");
		middleElementRadius = newMiddleElementRadius;
	}

	constexpr float getInnerRadius() const noexcept {
		return innerRadius;
	}

	constexpr void setInnerRadius(float newInnerRadius) {
		throwIfNegative(newInnerRadius, "inner radius");
		innerRadius = newInnerRadius;
	}

	constexpr float getOuterRadius() const noexcept {
		return outerRadius;
	}

	constexpr void setOuterRadius(float newOuterRadius) {
		throwIfNegative(newOuterRadius, "outer radius");
		outerRadius = newOuterRadius;
	}

	constexpr float getHeight() const noexcept {
		return height;
	}

	constexpr void setHeight(float newHeight) {
		throwIfNegative(newHeight, "height");
		height = newHeight;
	}

	constexpr float getConnectorHeight() const noexcept {
		return connectorHeight;
	}

	constexpr void setConnectorHeight(float newConnectorHeight) {
		throwIfNegative(newConnectorHeight, "connector height");
		connectorHeight = newConnectorHeight;
	}

	constexpr unsigned getConnectorCount() const noexcept {
		return connectorCount;
	}

	constexpr void setConnectorCount(unsigned newConnectorCount) {
		throwIfEqualToZero(newConnectorCount, "connector count");
		connectorCount = newConnectorCount;
	}

private:
	constexpr void throwIfEqualToZero(unsigned value, std::string_view var) {
		if(value == 0U) {
			throw std::invalid_argument{"WheelModel: " + std::string{var} + " cannot be equal to 0"};
		}
	}

	constexpr void throwIfNegative(float value, std::string_view var) {
		if(value <= 0.0f) {
			throw std::invalid_argument{"WheelModel: " + std::string{var} + " must be greater than 0"};
		}
	}

	float middleElementRadius = DEFAULT_MIDDLE_ELEMENT_RADIUS;
	float innerRadius = DEFAULT_INNER_RADIUS;
	float outerRadius = DEFAULT_OUTER_RADIUS;
	float height = DEFAULT_HEIGHT;
	float connectorHeight = DEFAULT_CONNECTOR_HEIGHT;

	unsigned connectorCount = DEFAULT_CONNECTOR_COUNT;
};
