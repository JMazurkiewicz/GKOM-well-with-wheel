#pragma once

#include "Graphics/Shader.h"
#include "MainWindow.h"
#include "Model/EnvironmentGlModel.h"
#include "Model/WellGlModel.h"
#include "View/EnvironmentGlView.h"
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
	void prepareWellModels();
	void prepareEnvironmentModel();

	void clear();
	void setupCamera();
	void updateCamera(
		GLuint MatrixID, 
		GLuint ModelMatrixID, 
		GLuint ViewMatrixID
	);
	void drawObjects();

	bool shouldClose() const;

	MainWindow& window;
	Shader mainShader;

	GLuint vao;

	EnvironmentGlModel environmentModel;
	EnvironmentGlView environmentView;

	WellGlModel model;
	WellGlView view;
};
