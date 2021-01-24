#pragma once

#include <stdexcept>

class EnvironmentModel {
public:
	static constexpr float DEFAULT_SIZE = 10.0f;

	EnvironmentModel() = default;
	EnvironmentModel(const EnvironmentModel&) = delete;
	EnvironmentModel& operator=(const EnvironmentModel&) = delete;

	constexpr float getSize() const noexcept {
		return size;
	}

	constexpr void setSize(float newSize) {
		if(newSize <= 0.0f) {
			throw std::invalid_argument{"EnvironmentModel: size must be greater than 0"};
		} else {
			size = newSize;
		}
	}

private:
	float size = DEFAULT_SIZE;
};
