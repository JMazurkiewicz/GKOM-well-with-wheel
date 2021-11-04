#include "WheelController.h"

#include <glm/ext.hpp>

namespace {
    constexpr int COLLAPSE_KEY = GLFW_KEY_RIGHT;
    constexpr int EXPAND_KEY = GLFW_KEY_LEFT;
}

WheelController::WheelController(const WellModel& basicModel)
    : basicModel{basicModel} { }

void WheelController::setModel(GlModel& wheelModel) {
    model = &wheelModel;
}

void WheelController::setView(DynamicGlView& wheelView) {
    view = &wheelView;
}

void WheelController::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void WheelController::update(float time) {
    if(canUpdate()) {
        const int sign = (expandKeyPressed ? 1 : -1);
        const float angle = speed * time * sign;
        const glm::vec3 translationVector{basicModel.getInnerRadius(),
                                          basicModel.getHeight() + basicModel.getWheelHeight(), 0.0f};
        const auto translation = glm::translate(-translationVector);
        const auto rotation = glm::rotate(angle, glm::vec3{1.0f, 0.0f, 0.0f});
        const auto translationBack = glm::translate(translationVector);

        model->transform(translationBack * rotation * translation);
        view->updateView();
    }
}

void WheelController::onKeyPress(int key) {
    switch(key) {
    case EXPAND_KEY:
        expandKeyPressed = true;
        break;
    case COLLAPSE_KEY:
        collapseKeyPressed = true;
        break;
    }
}

void WheelController::onKeyRelease(int key) {
    switch(key) {
    case EXPAND_KEY:
        expandKeyPressed = false;
        break;
    case COLLAPSE_KEY:
        collapseKeyPressed = false;
        break;
    }
}

bool WheelController::canUpdate() const {
    return expandKeyPressed != collapseKeyPressed && model != nullptr && view != nullptr;
}
