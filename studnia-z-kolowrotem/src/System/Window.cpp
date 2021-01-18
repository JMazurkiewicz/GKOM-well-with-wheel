#include "Window.h"

#include <stdexcept>

Window::Window(int width, int height, const char* title, Style style) : width{width}, height{height}, handle{nullptr} {
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	const bool resizable = (style & RESIZABLE);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if(handle == nullptr) {
		throw std::runtime_error{"Failed to open glfw window."};
	}

	glfwMakeContextCurrent(handle);
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

Window::~Window() {
	glfwDestroyWindow(handle);
}

bool Window::shouldClose() const {
	return glfwWindowShouldClose(handle);
}

void Window::swapBuffers() {
	glfwSwapBuffers(handle);
}
