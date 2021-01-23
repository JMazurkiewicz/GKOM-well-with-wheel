#pragma once

class WheelModel {
public:
	static constexpr float DEFAULT_MIDDLE_ELEMENT_RADIUS = 0.02f;
	static constexpr float DEFAULT_INNER_RADIUS = 0.1f;
	static constexpr float DEFAULT_OUTER_RADIUS = 0.12f;
	static constexpr float DEFAULT_HEIGHT = 0.1f;
	static constexpr float DEFAULT_CONNECTOR_HEIGHT = 0.08f;

	static constexpr unsigned DEFAULT_CONNECTOR_COUNT = 8;

	WheelModel() = default;
	WheelModel(const WheelModel&) = delete;
	WheelModel& operator=(const WheelModel&) = delete;

	float getMiddleElementRadius() const noexcept;
	void setMiddleElementRadius(float newMiddleElementRadius);

	float getInnerRadius() const noexcept;
	void setInnerRadius(float newInnerRadius);

	float getOuterRadius() const noexcept;
	void setOuterRadius(float newOuterRadius);

	float getHeight() const noexcept;
	void setHeight(float newHeight);

	float getConnectorHeight() const noexcept;
	void setConnectorHeight(float newConnectorHeight);

	unsigned getConnectorCount() const noexcept;
	void setConnectorCount(unsigned newConnectorCount);

private:
	float middleElementRadius = DEFAULT_MIDDLE_ELEMENT_RADIUS;
	float innerRadius = DEFAULT_INNER_RADIUS;
	float outerRadius = DEFAULT_OUTER_RADIUS;
	float height = DEFAULT_HEIGHT;
	float connectorHeight = DEFAULT_CONNECTOR_HEIGHT;

	unsigned connectorCount = DEFAULT_CONNECTOR_COUNT;
};
