#pragma once

#include "Graphics/Shader.h"
#include "MainWindow.h"
#include "Model/EnvironmentGlModel.h"
#include "Model/WellGlModel.h"
#include "View/GlView.h"
#include "View/WellGlView.h"

class Scene {
public:
	explicit Scene(MainWindow& window);
	~Scene();

	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	void start();

private:
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
	GlView environmentView;

	WellGlModel model;
	WellGlView view;
};
