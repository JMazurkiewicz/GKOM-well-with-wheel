#include "Window.h"

#include "Controler/KeyboardListener.h"
#include "Controler/MouseListener.h"

#include <stdexcept>

Window::Window(int width, int height, const char* title) : width{width}, height{height}, handle{nullptr} {
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, 0);

	handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if(handle == nullptr) {
		throw std::runtime_error{"Window: failed to open glfw window"};
	}

	registerCallbacks();
}

Window::~Window() {
	glfwDestroyWindow(handle);
}

int Window::getWidth() const noexcept {
	return width;
}

int Window::getHeight() const noexcept {
	return height;
}

GLFWwindow* Window::getHandle() const {
	return handle;
}

float Window::getAspectRatio() const {
	return static_cast<float>(getWidth()) / static_cast<float>(getHeight());
}

void Window::makeContextCurrent() {
	glfwMakeContextCurrent(getHandle());
}

void Window::swapBuffers() {
	glfwSwapBuffers(getHandle());
}

bool Window::shouldClose() const {
	return glfwWindowShouldClose(getHandle());
}

void Window::registerCallbacks() {
	glfwSetKeyCallback(getHandle(), KeyboardListener::callback);
	glfwSetCursorPosCallback(getHandle(), MouseListener::callback);
	glfwSetInputMode(getHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
