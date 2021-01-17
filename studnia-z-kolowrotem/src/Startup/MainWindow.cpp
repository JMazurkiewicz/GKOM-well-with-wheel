#include "MainWindow.h"

namespace {
	constexpr int WIDTH = 1000;
	constexpr int HEIGHT = 1000;
	constexpr char TITLE[] = "Studnia z kolowrotkiem";
}

MainWindow::MainWindow() : Window(WIDTH, HEIGHT, TITLE) {
	glViewport(0, 0, getWidth(), getHeight());
	glfwSetInputMode(getHandle(), GLFW_STICKY_KEYS, GL_TRUE);
}
