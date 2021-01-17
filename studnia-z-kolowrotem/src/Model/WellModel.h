#pragma once

#include <glm/glm.hpp>

/**
 * @brief Parametric model of the well.
 */
class WellModel {
public:
	static constexpr float DEFAULT_INNER_RADIUS = 10.0f;
	static constexpr float DEFAULT_BRICK_WIDTH = 2.0f;
	static constexpr float DEFAULT_BRICK_HEIGHT = 3.0f;
	static constexpr float DEFAULT_LAYER_ROTATION_ANGLE = 15.0f;

	static constexpr unsigned DEFAULT_SIDE_COUNT = 18;
	static constexpr unsigned DEFAULT_LAYER_COUNT = 10;

	static constexpr float INNER_RADIUS_LOWER_BOUND = 5.0f;
	static constexpr float INNER_RADIUS_UPPER_BOUND = 200.0f;

	static constexpr float BRICK_WIDTH_LOWER_BOUND = 2.0f;
	static constexpr float BRICK_WIDTH_UPPER_BOUND = 5.0f;

	static constexpr float BRICK_HEIGHT_LOWER_BOUND = 2.0f;
	static constexpr float BRICK_HEIGHT_UPPER_BOUND = 5.0f;

	static constexpr unsigned SIDE_COUNT_LOWER_BOUND = 4;
	static constexpr unsigned SIDE_COUNT_UPPER_BOUND = 32;

	static constexpr unsigned LAYER_COUNT_LOWER_BOUND = 1;
	static constexpr unsigned LAYER_COUNT_UPPER_BOUND = 12;

	WellModel();

	WellModel(const WellModel&) = delete;
	WellModel& operator=(const WellModel&) = delete;

	glm::vec3 getBasePoint() const;
	void setBasePoint(const glm::vec3& newBasePoint);

	float getInnerRadius() const noexcept;
	void setInnerRadius(float newInnerRadius);

	float getBrickWidth() const noexcept;
	void setBrickWidth(float newBrickWidth);

	float getBrickHeight() const noexcept;
	void setBrickHeight(float newBrickHeight);
	
	float getLayerRotationAngle() const noexcept;
	void setLayerRotationAngle(float newLayerRotationAngle);

	unsigned getSideCount() const noexcept;
	void setSideCount(unsigned newSideCount);

	unsigned getLayerCount() const noexcept;
	void setLayerCount(unsigned newLayerCount);

private:
	glm::f32vec3 basePoint;
	
	float innerRadius;
	float brickWidth;
	float brickHeight;
	float layerRotationAngle;

	unsigned sideCount;
	unsigned layerCount;
};
