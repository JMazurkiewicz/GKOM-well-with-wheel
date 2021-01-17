#include "MainWindow.h"

namespace {
	constexpr int WIDTH = 800;
	constexpr int HEIGHT = 600;
	constexpr char TITLE[] = "Studnia z kolowrotkiem";
}

MainWindow::MainWindow() : Window(WIDTH, HEIGHT, TITLE) {
	glViewport(0, 0, WIDTH, HEIGHT);
	glfwSetInputMode(getHandle(), GLFW_STICKY_KEYS, GL_TRUE);
}
