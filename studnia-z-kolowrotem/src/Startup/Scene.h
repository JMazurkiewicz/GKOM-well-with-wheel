#pragma once

#include "Graphics/Shader.h"
#include "MainWindow.h"
#include "Model/WellGlModel.h"
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

	void clear();
	void updateCamera();
	void drawObjects();

	bool shouldClose() const;

	MainWindow& window;
	Shader mainShader;

	GLuint vao;

	WellGlModel model;
	WellGlView view;
};
