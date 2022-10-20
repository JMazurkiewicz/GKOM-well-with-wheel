#pragma once

#include "GlModel/GlModel.h"
#include "Graphics/Texture.h"

#include <GL/glew.h>

class GlView {
public:
    GlView();
    virtual ~GlView();

    GlView(const GlView&) = delete;
    GlView& operator=(const GlView&) = delete;

    void setModel(const GlModel& newModel);
    void draw();

protected:
    virtual void updateModel() = 0;

    GLuint vbo;
    GLuint ebo;

    const GlModel* model;
};
