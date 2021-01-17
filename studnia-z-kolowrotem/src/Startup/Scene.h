#pragma once

#include "Graphics/Shader.h"
#include "MainWindow.h"
#include "Model/WellGlModel.h"
#include "System/FpsLogger.h"
#include "View/WellGlView.h"

class Scene {
public:
	Scene(MainWindow& window);
	~Scene();

	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	void start();

private:
	void prepare();
	void prepareModels();
	void prepareCamera();
	void printInfo() const;

	void updateCamera();

	bool shouldClose() const;

	MainWindow& window;
	Shader mainShader;

	GLuint vao;
	FpsLogger fpsLogger;

	WellGlModel model;
	WellGlView view;
};
