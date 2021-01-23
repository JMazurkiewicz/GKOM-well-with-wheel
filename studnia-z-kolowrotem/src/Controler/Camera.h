#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include "MouseListener.h"
#include "KeyboardListener.h"

class Camera : public MouseListener, public KeyboardListener {
public:
    explicit Camera(Window& window);

    const glm::mat4& getProjectionMatrix();
    const glm::mat4& getViewMatrix();
    const glm::mat4& getModelMatrix();
    glm::mat4 update();

protected:
    void onMove(double x, double y) override;
    void onPress(int key) override;
    void onRelease(int key) override;

private:
    int width;
    int height;

    glm::mat4 projectionMatrix;
    glm::mat4 viewMatrix;
    glm::mat4 modelMatrix;

    float lastX = 800 / 2.0f;
    float lastY = 600 / 2.0f;
    float yaw = -90.0f;
    float pitch = 0.0f;
    bool firstMove = true;

    const float cameraSpeed = 0.1f;
    const float sensitivity = 0.3f;

    const float minHeight = 0.2f;
    const float maxHeight = 5.0f;

    glm::vec3 cameraPos = glm::vec3(0.0f, minHeight, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

    bool keyPressedW = false;
    bool keyPressedA = false;
    bool keyPressedS = false;
    bool keyPressedD = false;
    bool keyPressedSpace = false;
    bool keyPressedCtrl = false;
};