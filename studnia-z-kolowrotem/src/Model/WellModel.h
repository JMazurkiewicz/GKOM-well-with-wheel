#pragma once

#include <glm/glm.hpp>

/**
 * @brief Basic well model.
 */
class WellModel {
public:
	static constexpr float DEFAULT_INNER_RADIUS = 3.0f;
	static constexpr float DEFAULT_OUTER_RADIUS = 8.0f;
	static constexpr float DEFAULT_HEIGHT = 4.0f;

	WellModel();

	WellModel(const WellModel&) = delete;
	WellModel& operator=(const WellModel&) = delete;

	float getInnerRadius() const noexcept;
	void setInnerRadius(float newInnerRadius);

	float getOuterRadius() const noexcept;
	void setOuterRadius(float newOuterRadius);

	float getHeight() const noexcept;
	void setHeight(float newHeight);

	void validateModel() const;

private:
	float innerRadius;
	float outerRadius;
	float height;
};
