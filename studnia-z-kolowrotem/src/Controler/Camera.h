#pragma once
#include "MouseListener.h"
#include "KeyboardListener.h"

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <numbers>

class Camera final : public MouseListener, public KeyboardListener {
public:
    explicit Camera(Window& window);

    Camera(const Camera&) = delete;
    Camera& operator=(const Camera&) = delete;

    const glm::mat4& getProjectionMatrix();
    const glm::mat4& getViewMatrix();
    const glm::mat4& getModelMatrix();
    const glm::mat4& getMVP();

    void update();

private:
    static constexpr float MAX_HEIGHT = 5.0f;
    static constexpr float MIN_HEIGHT = 0.2f;
    static constexpr float CAMERA_SPEED = 0.1f;
    static constexpr float SENSITIVITY = 0.008f;
    static constexpr float MAX_PITCH = (std::numbers::pi_v<float> / 2.0f) - 0.02f;
    static constexpr float MIN_PITCH = -MAX_PITCH;

    void onCursorMove(double x, double y) override;
    void onKeyPress(int key) override;
    void onKeyRelease(int key) override;

    void adjustHeight();

    const glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    const glm::mat4 modelMatrix;
    glm::mat4 mvp = glm::mat4{1.0f};

    float lastX;
    float lastY;
    float yaw = -std::numbers::pi_v<float> / 2.0f;
    float pitch = 0.0f;
    bool firstMove = true;

    glm::vec3 cameraPos = glm::vec3(0.0f, MIN_HEIGHT, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    bool moveForwardKeyPressed = false;
    bool moveBackwardKeyPressed = false;
    bool moveLeftKeyPressed = false;
    bool moveRightKeyPressed = false;
    bool moveUpKeyPressed = false;
    bool moveDownKeyPressed = false;
};
