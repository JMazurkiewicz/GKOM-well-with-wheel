#include "GlProgram.h"

#include "ShaderException.h"

GlProgram::GlProgram()
    : id{glCreateProgram()} { }

GlProgram::~GlProgram() {
    glDeleteProgram(id);
}

void GlProgram::attachShader(Shader& shader) {
    glAttachShader(id, shader.getId());
}

void GlProgram::link() {
    glLinkProgram(id);

    GLint success = 0;
    glGetProgramiv(id, GL_LINK_STATUS, &success);
    if(!success) {
        throw ShaderException{ShaderErrc::SHADER_PROGRAM_LINKING, id};
    }
}

void GlProgram::use() {
    glUseProgram(id);
}

GLint GlProgram::getUniformLocation(const char* name) {
    return glGetUniformLocation(id, name);
}
