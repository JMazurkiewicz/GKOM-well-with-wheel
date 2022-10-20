#pragma once

#include <filesystem>

#include <GL/glew.h>

enum class ShaderType : GLuint {
    UNKNOWN = 0,
    VERTEX = GL_VERTEX_SHADER,
    FRAGMENT = GL_FRAGMENT_SHADER,
};

ShaderType getShaderType(const std::filesystem::path& path);
