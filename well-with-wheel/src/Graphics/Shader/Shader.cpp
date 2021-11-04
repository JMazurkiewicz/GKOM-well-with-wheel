#include "Shader.h"

#include "ShaderException.h"

#include <fstream>
#include <iterator>

Shader::Shader(const std::filesystem::path& path) {
    const std::string code = loadShaderCode(path);
    const ShaderType type = getShaderType(path);
    compileShader(code, type);
}

Shader::~Shader() {
    glDeleteShader(id);
}

GLuint Shader::getId() const noexcept {
    return id;
}

std::string Shader::loadShaderCode(const std::filesystem::path& path) {
    std::ifstream file{path};
    if(!file.is_open()) {
        throw std::ios_base::failure{"Shader: std::ifstream failed to open \"" + path.string() + "\" file"};
    } else {
        file.exceptions(std::ios::failbit | std::ios::badbit);
    }

    const auto fileSize = static_cast<std::string::size_type>(std::filesystem::file_size(path));
    std::string content;
    content.reserve(fileSize);
    content.assign(std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{});
    return content;
}

void Shader::compileShader(const std::string& code, ShaderType type) {
    id = glCreateShader(static_cast<GLuint>(type));

    const GLchar* const codePtr = code.c_str();
    glShaderSource(id, 1, &codePtr, nullptr);
    glCompileShader(id);

    GLint success = 0;
    glGetShaderiv(id, GL_COMPILE_STATUS, &success);
    if(!success) {
        throw ShaderException{ShaderErrc::SHADER_COMPILATION, id};
    }
}
