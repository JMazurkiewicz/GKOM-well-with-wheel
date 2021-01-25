#include "Camera.h"

#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(Window& window)
	: width{window.getWidth()}, height{window.getHeight()}
{
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

void Camera::onKeyPress(int key) {
	switch(key) {
	case GLFW_KEY_W:
		keyPressedW = true;
		break;

	case GLFW_KEY_S:
		keyPressedS = true;
		break;

	case GLFW_KEY_A:
		keyPressedA = true;
		break;

	case GLFW_KEY_D:
		keyPressedD = true;
		break;

	case GLFW_KEY_SPACE:
		keyPressedSpace = true;
		break;

	case GLFW_KEY_LEFT_CONTROL:
		keyPressedCtrl = true;
		break;
	}
}

void Camera::onKeyRelease(int key) {
	switch(key) {
	case GLFW_KEY_W:
		keyPressedW = false;
		break;

	case GLFW_KEY_S:
		keyPressedS = false;
		break;

	case GLFW_KEY_A:
		keyPressedA = false;
		break;

	case GLFW_KEY_D:
		keyPressedD = false;
		break;

	case GLFW_KEY_SPACE:
		keyPressedSpace = false;
		break;

	case GLFW_KEY_LEFT_CONTROL:
		keyPressedCtrl = false;
		break;
	}
}

void Camera::onCursorMove(double x, double y) {
	if(firstMove) {
		lastX = static_cast<float>(x);
		lastY = static_cast<float>(y);
		firstMove = false;
	}

	float xoffset = static_cast<float>(x) - lastX;
	float yoffset = lastY - static_cast<float>(y);
	lastX = static_cast<float>(x);
	lastY = static_cast<float>(y);

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

void Camera::update() {
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

	const float ratio = static_cast<float>(width) / static_cast<float>(height);
	projectionMatrix = glm::perspective(glm::radians(45.0f), ratio, 0.1f, 100.0f);
	viewMatrix = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	modelMatrix = glm::mat4(1.0f);
	mvp = projectionMatrix * viewMatrix * modelMatrix;
}
