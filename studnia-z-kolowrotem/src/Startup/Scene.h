#pragma once

#include "Controler/Camera.h"
#include "Graphics/Shader.h"
#include "MainWindow.h"
#include "Environment.h"
#include "Well.h"

class Scene {
public:
	explicit Scene(MainWindow& window);
	~Scene();

	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	void start();

private:
	void clear();
	void setupCamera();
	void updateCamera(GLuint &MatrixID, GLuint &ModelMatrixID, GLuint &ViewMatrixID);
	void update();

	bool shouldClose() const;

	MainWindow& window;
	GLuint vao;
	Camera camera;

	Shader mainShader;

	Well well;
	Environment environment;
};
