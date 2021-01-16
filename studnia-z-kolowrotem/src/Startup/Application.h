#pragma once

#include <fstream>
#include "MainWindow.h"
#include "Model/WellGlModel.h"
#include "System/FpsLogger.h"
#include "View/WellGlView.h"

class Application {
public:
	Application(MainWindow& window);
	~Application();

	Application(const Application&) = delete;
	Application& operator=(const Application&) = delete;

	void run();

private:
	void prepare();
	void prepareWellGlModel();

	bool shouldClose() const;

	MainWindow& window;

	GLuint vao;
	FpsLogger fpsLogger;

	WellGlModel model;
	WellGlView view;
};
