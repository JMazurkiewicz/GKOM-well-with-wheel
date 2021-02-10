#pragma once

#include "ShaderType.h"

#include <filesystem>
#include <GL/glew.h>
#include <string>

class Shader {
public:
	explicit Shader(const std::filesystem::path& path);
	~Shader();

	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;

	GLuint getId() const noexcept;

private:
	std::string loadShaderCode(const std::filesystem::path& path);
	void compileShader(const std::string& code, ShaderType type);

	GLuint id;
};
