#include "Window.h"

#include "Controler/KeyboardListener.h"
#include "Controler/MouseListener.h"
#include <stdexcept>

#pragma warning(disable:26812)

Window::Window(int width, int height, const char* title, Style style) : width{width}, height{height}, handle{nullptr} {
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, static_cast<bool>(style & RESIZABLE));

	handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if(handle == nullptr) {
		throw std::runtime_error{"Window: failed to open glfw window"};
	}

	registerCallbacks();
	glfwMakeContextCurrent(handle);
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

bool Window::shouldClose() const {
	return glfwWindowShouldClose(handle);
}

void Window::swapBuffers() {
	glfwSwapBuffers(handle);
}

void Window::registerCallbacks() {
	glfwSetKeyCallback(getHandle(), KeyboardListener::callback);
	glfwSetCursorPosCallback(getHandle(), MouseListener::callback);
	glfwSetInputMode(getHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
