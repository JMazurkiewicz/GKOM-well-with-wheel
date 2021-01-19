#pragma once

#include <GL/glew.h>

class EnvironmentGlModel;

class EnvironmentGlView {
public:
	EnvironmentGlView();
	explicit EnvironmentGlView(const EnvironmentGlModel& model);
	~EnvironmentGlView();

	EnvironmentGlView(const EnvironmentGlView&) = delete;
	EnvironmentGlView& operator=(const EnvironmentGlView&) = delete;

	void setModel(const EnvironmentGlModel& newModel);
	void draw();

private:
	GLuint vbo;
	GLuint ebo;

	const EnvironmentGlModel* model;
};