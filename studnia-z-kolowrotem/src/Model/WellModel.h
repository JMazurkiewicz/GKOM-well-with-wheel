#pragma once

#include <stdexcept>

class WellModel {
public:
	static constexpr float DEFAULT_INNER_RADIUS = 0.6f;
	static constexpr float DEFAULT_OUTER_RADIUS = 0.8f;
	static constexpr float DEFAULT_HEIGHT = 0.5f;
	static constexpr float DEFAULT_WHEEL_HEIGHT = 1.0f;

	static constexpr float DEFAULT_BRACKET_RADIUS = 0.1f;
	static constexpr float DEFAULT_BRACKET_HEIGHT = 0.8f;
	static constexpr float DEFAULT_LOG_HEIGHT = 0.2f;

	constexpr WellModel() = default;
	WellModel(const WellModel&) = delete;
	WellModel& operator=(const WellModel&) = delete;

	float getInnerRadius() const noexcept;
	void setInnerRadius(float newInnerRadius);

	float getOuterRadius() const noexcept;
	void setOuterRadius(float newOuterRadius);

	float getHeight() const noexcept;
	void setHeight(float newHeight);

	float getWheelHeight() const noexcept;
	void setWheelHeight(float newWheelHeight);

	float getBracketRadius() const noexcept;
	void setBracketRadius(float newBracketRadius);

	float getBracketHeight() const noexcept;
	void setBrackedHeight(float newBracketHeight);

	constexpr float getLogHeight() const noexcept {
		return logHeight;
	}

	constexpr void setLogHeight(float newLogHeight) {
		if(newLogHeight <= 0.0f) {
			throw std::invalid_argument{"Class: log height must be greater than 0"};
		} else {
			logHeight = newLogHeight;
		}
	}

	void validateModel() const;

private:
	float innerRadius = DEFAULT_INNER_RADIUS;
	float outerRadius = DEFAULT_OUTER_RADIUS;
	float height = DEFAULT_HEIGHT;
	float wheelHeight = DEFAULT_WHEEL_HEIGHT;

	float bracketRadius = DEFAULT_BRACKET_RADIUS;
	float bracketHeight = DEFAULT_BRACKET_HEIGHT;
	float logHeight = DEFAULT_LOG_HEIGHT;
};
