#pragma once

#include <GL/glew.h>
#include "GlModel/GlModel.h"
#include "Graphics/Texture.h"

class GlView {
public:
	GlView();
	explicit GlView(const GlModel& model);
	~GlView();

	GlView(const GlView&) = delete;
	GlView& operator=(const GlView&) = delete;

	void setModel(const GlModel& newModel);
	void update();
	void draw();

protected:
	GLuint vbo;
	GLuint ebo;

	const GlModel* model;
};