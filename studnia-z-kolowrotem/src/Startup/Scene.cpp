#include "Scene.h"

#include "Controler/Camera.h"
#include "ModelGeneration/WellGlModelGenerator.h"
#include "Model/WellModel.h"
#include <thread>

namespace this_thread = std::this_thread;
using namespace std::chrono_literals;

Scene::Scene(MainWindow& window)
	: window{window}, mainShader{"gl_05.vert", "gl_05.frag"},
	vao{0}, fpsLogger{"fps.log"} {
	prepare();
}

Scene::~Scene() {
	glDeleteVertexArrays(1, &vao);
}

void Scene::start() {
	do {
		fpsLogger.log();
		glClear(GL_COLOR_BUFFER_BIT);

		view.draw();
		updateCamera();

		window.swapBuffers();
		this_thread::sleep_for(10ms); // @todo fix framerate
		glfwPollEvents();
	} while(!shouldClose());
}

void Scene::prepare() {
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Camera::init();

	prepareModels();
	prepareCamera();
	printInfo();
}

void Scene::prepareModels() {
	WellModel rawModel;

	rawModel.setLayerCount(1);
	rawModel.setSideCount(4);
	assert(rawModel.getLayerCount() == 1);
	assert(rawModel.getSideCount() == 4);

	WellGlModelGenerator modelGenerator{rawModel};
	model = modelGenerator.generate();
	view.setModel(model);
}

void Scene::prepareCamera() {
	glfwSetKeyCallback(window.getHandle(), Camera::keyCallback);
	glfwSetInputMode(window.getHandle(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glfwSetCursorPosCallback(window.getHandle(), Camera::mouseCallback);
}

void Scene::printInfo() const {
	std::cout << model << '\n'
		<< view << '\n';
}

void Scene::updateCamera() {
	glm::mat4 cameraMatrix = Camera::update();
	GLuint MatrixID = glGetUniformLocation(mainShader.getProgramId(), "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

bool Scene::shouldClose() const {
	return glfwGetKey(window.getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS ||
		   window.shouldClose();
}
