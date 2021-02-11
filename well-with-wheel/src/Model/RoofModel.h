#pragma once

#include <stdexcept>
#include <string_view>

class RoofModel {
public:
	static constexpr float DEFAULT_ANGLE = 0.7853981f;
	static constexpr float DEFAULT_MIN_TILE_LENGTH = 0.7f;
	static constexpr float DEFAULT_MAX_TILE_LENGTH = 1.0f;
	static constexpr float DEFAULT_TILE_HEIGHT = 0.05f;
	static constexpr unsigned DEFAULT_ROOF_TILE_COUNT = 20;
	
	constexpr RoofModel() = default;
	RoofModel(const RoofModel&) = delete;
	RoofModel& operator=(const RoofModel&) = delete;

	constexpr float getAngle() const noexcept {
		return angle;
	}

	constexpr void setAngle(float newAngle) {
		throwIfNegative(newAngle, "angle");
		angle = newAngle;
	}

	constexpr float getMinTileLength() const noexcept {
		return minTileLength;
	}

	constexpr void setMinTileLength(float newMinTileLength) {
		throwIfNegative(newMinTileLength, "min tile length");
		minTileLength = newMinTileLength;
	}

	constexpr float getMaxTileLength() const noexcept {
		return maxTileLength;
	}

	constexpr void setMaxTileLength(float newMaxTileLength) {
		throwIfNegative(newMaxTileLength, "max tile length");
		minTileLength = newMaxTileLength;
	}

	constexpr float getTileHeight() const noexcept {
		return tileHeight;
	}

	constexpr void setTileHeight(float newTileHeight) {
		throwIfNegative(newTileHeight, "tile height");
		tileHeight = newTileHeight;
	}

	constexpr unsigned getTileCount() const noexcept {
		return tileCount;
	}

	constexpr void setTileCount(unsigned newTileCount) {
		throwIfEqualToZero(newTileCount, "tile count");
		tileCount = newTileCount;
	}

private:
	constexpr void throwIfEqualToZero(unsigned value, std::string_view var) {
		if(value == 0U) {
			throw std::invalid_argument{"RoofModel: " + std::string{var} + " cannot be equal to 0"};
		}
	}

	constexpr void throwIfNegative(float value, std::string_view var) {
		if(value <= 0.0f) {
			throw std::invalid_argument{"RoofModel: " + std::string{var} + " must be greater than 0"};
		}
	}

	float angle = DEFAULT_ANGLE;
	float minTileLength = DEFAULT_MIN_TILE_LENGTH;
	float maxTileLength = DEFAULT_MAX_TILE_LENGTH;
	float tileHeight = DEFAULT_TILE_HEIGHT;

	unsigned tileCount = DEFAULT_ROOF_TILE_COUNT;
};
