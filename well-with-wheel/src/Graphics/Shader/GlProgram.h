#pragma once

#include "Shader.h"

#include <GL/glew.h>

class GlProgram {
public:
    GlProgram();
    ~GlProgram();

    GlProgram(const GlProgram&) = delete;
    GlProgram operator=(const GlProgram&) = delete;

    void attachShader(Shader& shader);
    void link();
    void use();

    GLint getUniformLocation(const char* name);

private:
    GLuint id;
};
