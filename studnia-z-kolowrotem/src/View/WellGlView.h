#pragma once

#include <GL/glew.h>
#include <ostream>

class WellGlModel;

class WellGlView {
public:
	WellGlView();
	explicit WellGlView(const WellGlModel& model);
	~WellGlView();

	WellGlView(const WellGlView&) = delete;
	WellGlView& operator=(const WellGlView&) = delete;

	void setModel(const WellGlModel& newModel);
	void draw();

private:
	GLuint vbo;
	GLuint ebo;
	GLuint nbo;

	const WellGlModel* model;
};
