#include "Scene.h"

#include "Controler/Camera.h"
#include <glm/ext.hpp>
#include <iostream>
#include "Model/EnvironmentModel.h"
#include "ModelGeneration/EnvironmentGlModelGenerator.h"
#include "ModelGeneration/WellGlModelGenerator.h"
#include "Model/WellModel.h"
#include <thread>

namespace this_thread = std::this_thread;
using namespace std::chrono_literals;

Scene::Scene(MainWindow& window)
: window{window}, mainShader{"assets/shaders/gl_05.vert", "assets/shaders/gl_05.frag"}, vao{0}
{	
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	Camera::init(window);

	prepareWellModels();
	prepareEnvironmentModel();
	glBindVertexArray(0);
}

Scene::~Scene() {
	glDeleteVertexArrays(1, &vao);
}

void Scene::start() {
	//glm::mat4 look{1};
	
	do {
		clear();

		glBindVertexArray(vao);
		drawObjects();
		updateCamera();

		//GLuint lookLoc = glGetUniformLocation(mainShader.getProgramId(), "model");
		//glUniformMatrix4fv(lookLoc, 1, GL_FALSE, glm::value_ptr(look));
		
		mainShader.useProgram();
		glBindVertexArray(0);

		window.swapBuffers();
		this_thread::sleep_for(10ms);
		glfwPollEvents();
	} while(!shouldClose());
}

void Scene::prepareWellModels() {
	WellModel basicModel{};
	WellGlModelGenerator glModelGenerator{basicModel};
	glModelGenerator.setSampleRate(64);

	model = glModelGenerator.generate();
	view.setModel(model);
}

void Scene::prepareEnvironmentModel() {
	EnvironmentModel basicModel;
	EnvironmentGlModelGenerator generator{basicModel};
	environmentModel = generator.generate();
	environmentView.setModel(environmentModel);
}

void Scene::clear() {
	glClearColor(0.529, 0.807, 0.921, 0.9);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::updateCamera() {
	glm::mat4 cameraMatrix = Camera::update();
	GLuint MatrixID = glGetUniformLocation(mainShader.getProgramId(), "MVP");
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(cameraMatrix));
}

void Scene::drawObjects() {
	environmentView.draw();
	view.draw();
}

bool Scene::shouldClose() const {
	return glfwGetKey(window.getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS ||
		   window.shouldClose();
}
