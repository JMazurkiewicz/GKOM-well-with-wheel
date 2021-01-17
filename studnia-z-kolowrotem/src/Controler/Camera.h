#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Camera {
public:
    static void init();
    static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
    static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);
    static glm::mat4 update();

private:
    static float lastX;
    static float lastY;
    static float yaw;
    static float pitch;
    static bool firstMouse;

    static const float cameraSpeed;
    static const float sensitivity;

    static const float minHeight;
    static const float maxHeight;

    static glm::vec3 cameraPos;
    static glm::vec3 cameraFront;
    static glm::vec3 cameraUp;

    static bool keyPressedW;
    static bool keyPressedA;
    static bool keyPressedS;
    static bool keyPressedD;
    static bool keyPressedSpace;
    static bool keyPressedCtrl;
};