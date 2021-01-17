#pragma once

#include <filesystem>
#include <GL/glew.h>
#include <string>

class Shader {
public:
	explicit Shader(const std::filesystem::path& vertexPath,
		            const std::filesystem::path& fragmentPath);

	Shader(const Shader&) = delete;
	Shader& operator=(const Shader&) = delete;

	~Shader();

	void useProgram() const;
	GLuint getProgramId() const noexcept;

private:
	std::string loadShaderCode(const std::filesystem::path& shaderPath);
	GLuint compileShader(const std::string& shaderCode, GLenum shaderType);
	void createProgram(GLuint vertexShaderId, GLuint fragmentShaderId);

	GLuint programId;
};