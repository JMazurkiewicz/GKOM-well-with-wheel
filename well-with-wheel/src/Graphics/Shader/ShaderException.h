#pragma once

#include <stdexcept>

#include <GL/glew.h>

enum class ShaderErrc { SHADER_COMPILATION, SHADER_PROGRAM_LINKING };

class ShaderException : public std::runtime_error {
public:
    explicit ShaderException(ShaderErrc code, GLuint associatedId);

    GLuint getAssociatedId() const noexcept;
    const char* getSituation() const noexcept;

private:
    std::string getInfoLog(ShaderErrc code, GLuint associatedId);
    std::string getShaderInfoLog(GLuint shaderId);
    std::string getProgramInfoLog(GLuint programId);

    ShaderErrc code;
    GLuint associatedId;
};
