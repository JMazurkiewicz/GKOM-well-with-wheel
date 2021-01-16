#pragma once

/**
 * @brief Parametric model of the well.
 * @author Jakub Mazurkiewicz 
 */

#include <glm/glm.hpp>

class WellModel {
public:
	WellModel();

	WellModel(const WellModel&) = delete;
	WellModel& operator=(const WellModel&) = delete;

	glm::vec3 getBasePoint() const;
	void setBasePoint(const glm::f32vec3& newBasePoint);

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
