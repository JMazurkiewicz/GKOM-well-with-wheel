#include "Camera.h"

#include <algorithm>
#include <cmath>

#include <glm/gtc/matrix_transform.hpp>

using namespace std::numbers;

namespace {
    constexpr int MOVE_FORWARD_KEY = GLFW_KEY_W;
    constexpr int MOVE_BACKWARD_KEY = GLFW_KEY_S;
    constexpr int MOVE_LEFT_KEY = GLFW_KEY_A;
    constexpr int MOVE_RIGHT_KEY = GLFW_KEY_D;
    constexpr int MOVE_UP_KEY = GLFW_KEY_SPACE;
    constexpr int MOVE_DOWN_KEY = GLFW_KEY_LEFT_CONTROL;
}

Camera::Camera(Window& window)
    : projectionMatrix{glm::perspective(pi_v<float> / 4.0f, window.getAspectRatio(), 0.1f, 100.0f)}
    , lastX{window.getWidth() / 2.0f}
    , lastY(window.getHeight() / 2.0f) {
    listenOn(window);
}

const glm::mat4& Camera::getProjectionMatrix() {
    return projectionMatrix;
}

const glm::mat4& Camera::getViewMatrix() {
    return viewMatrix;
}

const glm::mat4& Camera::getModelMatrix() {
    return modelMatrix;
}

const glm::mat4& Camera::getMVP() {
    return mvp;
}

void Camera::update() {
    if(moveForwardKeyPressed != moveBackwardKeyPressed) {
        const int direction = (moveForwardKeyPressed ? 1 : -1);
        cameraPos += direction * CAMERA_SPEED * cameraFront;
    }

    if(moveLeftKeyPressed != moveRightKeyPressed) {
        const int direction = (moveRightKeyPressed ? 1 : -1);
        const auto cameraSide = glm::normalize(glm::cross(cameraFront, cameraUp));
        cameraPos += direction * CAMERA_SPEED * cameraSide;
    }

    if(moveUpKeyPressed != moveDownKeyPressed) {
        const int direction = (moveUpKeyPressed ? 1 : -1);
        cameraPos += direction * CAMERA_SPEED * cameraUp;
    }

    cameraPos.y = std::ranges::clamp(cameraPos.y, MIN_HEIGHT, MAX_HEIGHT);
    viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
    mvp = projectionMatrix * viewMatrix * modelMatrix;
}

void Camera::onCursorMove(double x, double y) {
    const float xPos = static_cast<float>(x);
    const float yPos = static_cast<float>(y);

    if(firstMove) [[unlikely]] {
        lastX = xPos;
        lastY = yPos;
        firstMove = false;
    }

    const float xOffset = (xPos - lastX) * SENSITIVITY;
    const float yOffset = (lastY - yPos) * SENSITIVITY;
    lastX = xPos;
    lastY = yPos;

    yaw += xOffset;
    pitch = std::ranges::clamp(pitch + yOffset, MIN_PITCH, MAX_PITCH);

    cameraFront =
        glm::normalize(glm::vec3{std::cos(yaw) * std::cos(pitch), std::sin(pitch), std::sin(yaw) * std::cos(pitch)});
}

void Camera::onKeyPress(int key) {
    switch(key) {
    case MOVE_FORWARD_KEY:
        moveForwardKeyPressed = true;
        break;
    case MOVE_BACKWARD_KEY:
        moveBackwardKeyPressed = true;
        break;
    case MOVE_LEFT_KEY:
        moveLeftKeyPressed = true;
        break;
    case MOVE_RIGHT_KEY:
        moveRightKeyPressed = true;
        break;
    case MOVE_UP_KEY:
        moveUpKeyPressed = true;
        break;
    case MOVE_DOWN_KEY:
        moveDownKeyPressed = true;
        break;
    }
}

void Camera::onKeyRelease(int key) {
    switch(key) {
    case MOVE_FORWARD_KEY:
        moveForwardKeyPressed = false;
        break;
    case MOVE_BACKWARD_KEY:
        moveBackwardKeyPressed = false;
        break;
    case MOVE_LEFT_KEY:
        moveLeftKeyPressed = false;
        break;
    case MOVE_RIGHT_KEY:
        moveRightKeyPressed = false;
        break;
    case MOVE_UP_KEY:
        moveUpKeyPressed = false;
        break;
    case MOVE_DOWN_KEY:
        moveDownKeyPressed = false;
        break;
    }
}
