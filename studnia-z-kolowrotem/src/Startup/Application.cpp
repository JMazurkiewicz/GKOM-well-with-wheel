#include "Application.h"

#include "ModelGeneration/WellGlModelGenerator.h"
#include "Model/WellModel.h"

Application::Application(MainWindow& window)
	: window{window}, vao{0}, fpsLogger{"fps.log"} {
	prepare();
}

Application::~Application() {
	glDeleteVertexArrays(1, &vao);
}

void Application::prepare() {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
}

void Application::prepareWellGlModel() {
	WellModel rawModel;

	WellGlModelGenerator modelGenerator{rawModel};
	model = modelGenerator.generate();

	view.setModel(model);
}

void Application::run() {
	do {
		fpsLogger.log();
		glClear(GL_COLOR_BUFFER_BIT);

		view.draw();

		window.swapBuffers();
		glfwPollEvents();
	} while(!shouldClose());
}

bool Application::shouldClose() const {
	return
		glfwGetKey(window.getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS ||
		window.shouldClose();
}
