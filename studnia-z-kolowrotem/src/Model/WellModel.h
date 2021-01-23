#pragma once

#include <glm/glm.hpp>

/**
 * @brief Basic well model.
 */
class WellModel {
public:
	static constexpr float DEFAULT_INNER_RADIUS = 0.6f;
	static constexpr float DEFAULT_OUTER_RADIUS = 0.8f;
	static constexpr float DEFAULT_HEIGHT = 0.8f;

	static constexpr float DEFAULT_BRACKET_RADIUS = 0.1f;
	static constexpr float DEFAULT_BRACKET_HEIGHT = 0.5f;

	WellModel() = default;
	WellModel(const WellModel&) = delete;
	WellModel& operator=(const WellModel&) = delete;

	float getInnerRadius() const noexcept;
	void setInnerRadius(float newInnerRadius);

	float getOuterRadius() const noexcept;
	void setOuterRadius(float newOuterRadius);

	float getHeight() const noexcept;
	void setHeight(float newHeight);

	float getBracketRadius() const noexcept;
	void setBracketRadius(float newBracketRadius);

	float getBracketHeight() const noexcept;
	void setBrackedHeight(float newBracketHeight);

	void validateModel() const;

private:
	float innerRadius = DEFAULT_INNER_RADIUS;
	float outerRadius = DEFAULT_OUTER_RADIUS;
	float height = DEFAULT_HEIGHT;

	float bracketRadius = DEFAULT_BRACKET_RADIUS;
	float bracketHeight = DEFAULT_BRACKET_HEIGHT;
};
