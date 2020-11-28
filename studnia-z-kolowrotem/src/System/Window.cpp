#include "Window.h"

Window::Window(int width, int height, const char* title, Style style) : handle{nullptr} {
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	const bool resizable = (style & RESIZABLE);
	glfwWindowHint(GLFW_RESIZABLE, resizable);

	handle = glfwCreateWindow(width, height, title, nullptr, nullptr);
	glfwMakeContextCurrent(handle);
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
