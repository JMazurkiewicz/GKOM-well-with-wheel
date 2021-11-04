#pragma once

#include <stdexcept>

class EnvironmentModel {
public:
    static constexpr float DEFAULT_SIZE = 64.0f;
    static constexpr float DEFAULT_HEIGHT = 40.0f;

    EnvironmentModel() = default;
    EnvironmentModel(const EnvironmentModel&) = delete;
    EnvironmentModel& operator=(const EnvironmentModel&) = delete;

    constexpr float getSize() const noexcept {
        return size;
    }

    constexpr void setSize(float newSize) {
        throwIfNegative(newSize, "size");
        size = newSize;
    }

    constexpr float getHeight() const noexcept {
        return height;
    }

    constexpr void setHeight(float newHeight) {
        throwIfNegative(newHeight, "height");
        height = newHeight;
    }

private:
    constexpr void throwIfNegative(float value, std::string_view var) {
        if(value <= 0.0f) {
            throw std::invalid_argument{"EnvironmentModel: " + std::string{var} + " must be greater than 0"};
        }
    }

    float size = DEFAULT_SIZE;
    float height = DEFAULT_HEIGHT;
};
