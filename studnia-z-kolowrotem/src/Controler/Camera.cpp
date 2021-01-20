#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

float Camera::width;
float Camera::height;

glm::mat4 Camera::projectionMatrix;
glm::mat4 Camera::viewMatrix;
glm::mat4 Camera::modelMatrix;

float Camera::lastX;
float Camera::lastY;
float Camera::yaw;
float Camera::pitch;
bool Camera::firstMouse;
const float Camera::cameraSpeed = 0.1f;
const float Camera::sensitivity = 0.3f;
const float Camera::minHeight = 0.2f;
const float Camera::maxHeight = 5.0f;
glm::vec3 Camera::cameraPos;
glm::vec3 Camera::cameraFront;
glm::vec3 Camera::cameraUp;
bool Camera::keyPressedW;
bool Camera::keyPressedA;
bool Camera::keyPressedS;
bool Camera::keyPressedD;
bool Camera::keyPressedSpace;
bool Camera::keyPressedCtrl;

void Camera::init(Window& window) {
	glfwSetKeyCallback(window.getHandle(), Camera::keyCallback);
	glfwSetCursorPosCallback(window.getHandle(), Camera::mouseCallback);
	glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	width = static_cast<float>(window.getWidth());
	height = static_cast<float>(window.getHeight());

	lastX = 800 / 2.0f;
	lastY = 600 / 2.0f;
	yaw = -90.0f;
	pitch = 0.0f;
	firstMouse = true;

	cameraPos = glm::vec3(0.0f, minHeight, 3.0f);
	cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
	cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);

	keyPressedW = false;
	keyPressedA = false;
	keyPressedS = false;
	keyPressedD = false;
	keyPressedSpace = false;
	keyPressedCtrl = false;
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

void Camera::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	const bool isNotReleased = action != GLFW_RELEASE;

	switch(key) {
	case GLFW_KEY_W:
		keyPressedW = isNotReleased;
		break;

	case GLFW_KEY_S:
		keyPressedS = isNotReleased;
		break;

	case GLFW_KEY_A:
		keyPressedA = isNotReleased;
		break;

	case GLFW_KEY_D:
		keyPressedD = isNotReleased;
		break;

	case GLFW_KEY_SPACE:
		keyPressedSpace = isNotReleased;
		break;

	case GLFW_KEY_LEFT_CONTROL:
		keyPressedCtrl = isNotReleased;
		break;
	}
}

void Camera::mouseCallback(GLFWwindow* window, double xpos, double ypos) {
	if(firstMouse) {
		lastX = static_cast<float>(xpos);
		lastY = static_cast<float>(ypos);
		firstMouse = false;
	}

	float xoffset = static_cast<float>(xpos) - lastX;
	float yoffset = lastY - static_cast<float>(ypos);
	lastX = static_cast<float>(xpos);
	lastY = static_cast<float>(ypos);

	xoffset *= sensitivity;
	yoffset *= sensitivity;

	yaw += xoffset;
	pitch += yoffset;

	if(pitch > 89.0f)
		pitch = 89.0f;
	if(pitch < -89.0f)
		pitch = -89.0f;

	glm::vec3 direction;
	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	cameraFront = glm::normalize(direction);
}

glm::mat4 Camera::update() {
	if(keyPressedW)
		cameraPos += cameraSpeed * cameraFront;

	if(keyPressedS)
		cameraPos -= cameraSpeed * cameraFront;

	if(keyPressedA)
		cameraPos -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	if(keyPressedD)
		cameraPos += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed;

	if(keyPressedSpace)
		cameraPos += cameraUp * cameraSpeed;

	if(keyPressedCtrl)
		cameraPos -= cameraUp * cameraSpeed;


	if(cameraPos.y > maxHeight)
		cameraPos.y = maxHeight;

	else if(cameraPos.y < minHeight)
		cameraPos.y = minHeight;


	projectionMatrix = glm::perspective(glm::radians(45.0f), width/height, 0.1f, 100.0f);
	viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	modelMatrix = glm::mat4(1.0f);

	return projectionMatrix * viewMatrix * modelMatrix;
}
