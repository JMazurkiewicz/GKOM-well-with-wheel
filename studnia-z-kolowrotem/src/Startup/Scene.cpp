#include "Scene.h"

#include "Controler/Camera.h"
#include <glm/ext.hpp>
#include <iostream>
#include <thread>

namespace this_thread = std::this_thread;
using namespace std::chrono_literals;

Scene::Scene(MainWindow& window)
: window{window}, vao{0}, camera{window},
mainShader{"assets/shaders/gl_05.vert", "assets/shaders/gl_05.frag"},
well{window}
{	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	camera.listenOn(window);
	glBindVertexArray(0);
}

Scene::~Scene() {
	glDeleteVertexArrays(1, &vao);
}

void Scene::start() {
	const GLuint programID = mainShader.getProgramId();
	GLuint MatrixID = glGetUniformLocation(programID, "MVP");
	GLuint ViewMatrixID = glGetUniformLocation(programID, "V");
	GLuint ModelMatrixID = glGetUniformLocation(programID, "M");
	GLuint TextureID = glGetUniformLocation(programID, "TextureSampler");
	GLuint LightID = glGetUniformLocation(programID, "LightPosWorld");

	do {
		clear();
		glUseProgram(programID);
		updateCamera(MatrixID, ViewMatrixID, ModelMatrixID);

		glUniform3f(LightID, 0.0f, 0.2f, 0.0f);

		glBindVertexArray(0);
		glBindVertexArray(vao);
		update();

		window.swapBuffers();
		this_thread::sleep_for(10ms);
		glfwPollEvents();
	} while(!shouldClose());
}

void Scene::clear() {
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::setupCamera() {
}

void Scene::updateCamera(GLuint &MatrixID, GLuint &ModelMatrixID, GLuint &ViewMatrixID) {
	camera.update();
	glm::mat4 projectionMatrix = camera.getProjectionMatrix();
	glm::mat4 viewMatrix = camera.getViewMatrix();
	glm::mat4 modelMatrix = camera.getModelMatrix();
	glm::mat4 cameraMatrix = camera.getMVP();

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(cameraMatrix));
	glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, glm::value_ptr(modelMatrix));
	glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}

void Scene::update() {
	environment.update();
	well.update();
}

bool Scene::shouldClose() const {
	return glfwGetKey(window.getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS ||
		   window.shouldClose();
}
