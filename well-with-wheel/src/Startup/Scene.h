#pragma once

#include "Controler/Camera.h"
#include "Graphics/Shader/GlProgram.h"
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
	void prepareShader();

	void clear();
	void update();
	void updateCamera(GLint& MatrixID, GLint& ModelMatrixID, GLint& ViewMatrixID);

	bool shouldClose() const;

	MainWindow& window;
	GLuint vao;
	Camera camera;

	GlProgram mainProgram;

	Well well;
	Environment environment;
};
