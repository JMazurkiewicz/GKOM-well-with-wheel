#include "Scene.h"

#include "Controler/Camera.h"
#include <glm/ext.hpp>
#include <iostream>
#include <thread>

namespace this_thread = std::this_thread;
using namespace std::chrono_literals;

Scene::Scene(MainWindow& window)
: window{window}, vao{0}, mainShader{"assets/shaders/gl_05.vert", "assets/shaders/gl_05.frag"}
{	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	Camera::init(window);
	glBindVertexArray(0);
}

Scene::~Scene() {
	glDeleteVertexArrays(1, &vao);
}

void Scene::start() {
	GLuint MatrixID = glGetUniformLocation(mainShader.getProgramId(), "MVP");
	GLuint ViewMatrixID = glGetUniformLocation(mainShader.getProgramId(), "V");
	GLuint ModelMatrixID = glGetUniformLocation(mainShader.getProgramId(), "M");
	GLuint TextureID = glGetUniformLocation(mainShader.getProgramId(), "TextureSampler");
	
	do {
		clear();

		glBindVertexArray(vao);
		update();
		updateCamera(MatrixID, ViewMatrixID, ModelMatrixID);
		
		mainShader.useProgram();
		glBindVertexArray(0);

		window.swapBuffers();
		this_thread::sleep_for(10ms);
		glfwPollEvents();
	} while(!shouldClose());
}

void Scene::clear() {
	glClearColor(0.529, 0.807, 0.921, 0.9);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::setupCamera() {
}

void Scene::updateCamera(
	GLuint MatrixID, 
	GLuint ModelMatrixID, 
	GLuint ViewMatrixID
) {
	glm::mat4 projectionMatrix = Camera::getProjectionMatrix();
	glm::mat4 viewMatrix = Camera::getViewMatrix();
	glm::mat4 modelMatrix = Camera::getModelMatrix();
	glm::mat4 cameraMatrix = Camera::update();

	//GLuint MatrixID = glGetUniformLocation(mainShader.getProgramId(), "MVP");
	//glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(cameraMatrix));

	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &cameraMatrix[0][0]);
	glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &modelMatrix[0][0]);
	glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &viewMatrix[0][0]);
}

void Scene::update() {
	environment.update();
	well.update();
}

bool Scene::shouldClose() const {
	return glfwGetKey(window.getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS ||
		   window.shouldClose();
}
