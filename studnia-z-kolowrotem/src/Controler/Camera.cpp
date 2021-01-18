#include "Camera.h"

constexpr auto WIDTH = 800;
constexpr auto HEIGHT = 600;

float Camera::lastX;
float Camera::lastY;
float Camera::yaw;
float Camera::pitch;
bool Camera::firstMouse;
const float Camera::cameraSpeed = 0.001f;
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

void Camera::init() {
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

void Camera::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mode) {
	if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);

	if(key == GLFW_KEY_W) {
		if(action == GLFW_RELEASE)
			keyPressedW = false;
		else
			keyPressedW = true;
	}

	if(key == GLFW_KEY_S) {
		if(action == GLFW_RELEASE)
			keyPressedS = false;
		else
			keyPressedS = true;
	}

	if(key == GLFW_KEY_A) {
		if(action == GLFW_RELEASE)
			keyPressedA = false;
		else
			keyPressedA = true;
	}

	if(key == GLFW_KEY_D) {
		if(action == GLFW_RELEASE)
			keyPressedD = false;
		else
			keyPressedD = true;
	}

	if(key == GLFW_KEY_SPACE) {
		if(action == GLFW_RELEASE)
			keyPressedSpace = false;
		else
			keyPressedSpace = true;
	}

	if(key == GLFW_KEY_LEFT_CONTROL) {
		if(action == GLFW_RELEASE)
			keyPressedCtrl = false;
		else
			keyPressedCtrl = true;
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


	const glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)WIDTH / (float)HEIGHT, 0.1f, 100.0f);
	const glm::mat4 view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
	const glm::mat4 model = glm::mat4(1.0f);

	return projection * view * model;;
}
