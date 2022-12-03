#include "MainWindow.h"

#include <array>

namespace {
    constexpr int WIDTH = 1000;
    constexpr int HEIGHT = 1000;
    constexpr auto TITLE = std::to_array("Studnia z kolowrotkiem");
}

MainWindow::MainWindow()
    : Window(WIDTH, HEIGHT, TITLE.data()) {
    glViewport(0, 0, getWidth(), getHeight());
    // FIXME emscripten "glfwSetInputMode called with GLFW_STICKY_KEYS mode not implemented."
    glfwSetInputMode(getHandle(), GLFW_STICKY_KEYS, GL_TRUE);
}
