#pragma once

#include <stdexcept>

class RoofModel {
public:
	static constexpr float DEFAULT_ANGLE = 0.7853981f;
	static constexpr float DEFAULT_MIN_TILE_LENGTH = 0.5f;
	static constexpr float DEFAULT_MAX_TILE_LENGTH = 0.7f;
	static constexpr float DEFAULT_TILE_HEIGHT = 0.05f;
	static constexpr unsigned DEFAULT_ROOF_TILE_COUNT = 20;
	
	constexpr RoofModel() = default;
	RoofModel(const RoofModel&) = delete;
	RoofModel& operator=(const RoofModel&) = delete;

	constexpr float getAngle() const noexcept {
		return angle;
	}

	constexpr void setAngle(float newAngle) {
		if(newAngle <= 0.0f) {
			throw std::invalid_argument{"RoofModel: angle must be greater than 0"};
		} else {
			angle = newAngle;
		}
	}

	constexpr float getMinTileLength() const noexcept {
		return minTileLength;
	}

	constexpr void setMinTileLength(float newMinTileLength) {
		if(newMinTileLength <= 0.0f) {
			throw std::invalid_argument{"RoofModel: min tile length must be greater than 0"};
		} else {
			minTileLength = newMinTileLength;
		}
	}

	constexpr float getMaxTileLength() const noexcept {
		return maxTileLength;
	}

	constexpr void setMaxTileLength(float newMaxTileLength) {
		if(newMaxTileLength <= 0.0f) {
			throw std::invalid_argument{"RoofModel: max tile length must be greater than 0"};
		} else {
			minTileLength = newMaxTileLength;
		}
	}

	constexpr float getTileHeight() const noexcept {
		return tileHeight;
	}

	constexpr void setTileHeight(float newTileHeight) {
		if(newTileHeight <= 0.0f) {
			throw std::invalid_argument{"RoofModel: tile height must be greater than 0"};
		} else {
			tileHeight = newTileHeight;
		}
	}

	constexpr unsigned getTileCount() const noexcept {
		return tileCount;
	}

	constexpr void setTileCount(unsigned newTileCount) {
		if(newTileCount == 0) {
			throw std::invalid_argument{"RoofModel: tile count must be greater than 0"};
		} else {
			tileCount = newTileCount;
		}
	}

private:
	float angle = DEFAULT_ANGLE;
	float minTileLength = DEFAULT_MIN_TILE_LENGTH;
	float maxTileLength = DEFAULT_MAX_TILE_LENGTH;
	float tileHeight = DEFAULT_TILE_HEIGHT;

	unsigned tileCount = DEFAULT_ROOF_TILE_COUNT;
};
