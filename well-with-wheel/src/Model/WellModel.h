#pragma once

#include <stdexcept>
#include <string_view>

class WellModel {
public:
    static constexpr float DEFAULT_INNER_RADIUS = 0.6f;
    static constexpr float DEFAULT_OUTER_RADIUS = 0.8f;
    static constexpr float DEFAULT_HEIGHT = 0.5f;
    static constexpr float DEFAULT_WHEEL_HEIGHT = 0.5f;

    static constexpr float DEFAULT_BRACKET_RADIUS = 0.1f;
    static constexpr float DEFAULT_BRACKET_HEIGHT = 0.8f;
    static constexpr float DEFAULT_LOG_HEIGHT = 0.2f;

    constexpr WellModel() = default;
    WellModel(const WellModel&) = delete;
    WellModel& operator=(const WellModel&) = delete;

    constexpr float getInnerRadius() const noexcept {
        return innerRadius;
    }

    constexpr void setInnerRadius(float newInnerRadius) {
        throwIfNegative(newInnerRadius, "inner radius");
        innerRadius = newInnerRadius;
    }

    constexpr float getOuterRadius() const noexcept {
        return outerRadius;
    }

    constexpr void setOuterRadius(float newOuterRadius) {
        throwIfNegative(newOuterRadius, "outer radius");
        outerRadius = newOuterRadius;
    }

    constexpr float getHeight() const noexcept {
        return height;
    }

    constexpr void setHeight(float newHeight) {
        throwIfNegative(newHeight, "height");
        height = newHeight;
    }

    constexpr float getWheelHeight() const noexcept {
        return wheelHeight;
    }

    constexpr void setWheelHeight(float newWheelHeight) {
        throwIfNegative(newWheelHeight, "wheel height");
        wheelHeight = newWheelHeight;
    }

    constexpr float getBracketRadius() const noexcept {
        return bracketRadius;
    }

    constexpr void setBracketRadius(float newBracketRadius) {
        throwIfNegative(newBracketRadius, "bracket radius");
        bracketRadius = newBracketRadius;
    }

    constexpr float getBracketHeight() const noexcept {
        return bracketHeight;
    }

    constexpr void setBrackedHeight(float newBracketHeight) {
        throwIfNegative(newBracketHeight, "bracket height");
        bracketHeight = newBracketHeight;
    }

    constexpr float getLogHeight() const noexcept {
        return logHeight;
    }

    constexpr void setLogHeight(float newLogHeight) {
        throwIfNegative(newLogHeight, "log height");
        logHeight = newLogHeight;
    }

private:
    constexpr void throwIfNegative(float value, std::string_view var) {
        if(value <= 0.0f) {
            throw std::invalid_argument{"WellModel: " + std::string{var} + " must be greater than 0"};
        }
    }

    float innerRadius = DEFAULT_INNER_RADIUS;
    float outerRadius = DEFAULT_OUTER_RADIUS;
    float height = DEFAULT_HEIGHT;
    float wheelHeight = DEFAULT_WHEEL_HEIGHT;

    float bracketRadius = DEFAULT_BRACKET_RADIUS;
    float bracketHeight = DEFAULT_BRACKET_HEIGHT;
    float logHeight = DEFAULT_LOG_HEIGHT;
};
