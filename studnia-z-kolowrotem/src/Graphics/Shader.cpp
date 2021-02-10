#include "Shader.h"

#include "LibraryExceptions/ShaderException.h"

#include <fstream>
#include <iterator>

Shader::Shader(const std::filesystem::path& vertexPath, const std::filesystem::path& fragmentPath) {
	const std::string vertexShaderCode = loadShaderCode(vertexPath);
	const std::string fragmentShaderCode = loadShaderCode(fragmentPath);

	const GLuint vertexShaderId = compileShader(vertexShaderCode, GL_VERTEX_SHADER);
	const GLuint fragmentShaderId = compileShader(fragmentShaderCode, GL_FRAGMENT_SHADER);

	auto cleanUpShaders = [&vertexShaderId, &fragmentShaderId] {
		glDeleteShader(vertexShaderId);
		glDeleteShader(fragmentShaderId);
	};

	try {
		createProgram(vertexShaderId, fragmentShaderId);
	} catch(...) {
		cleanUpShaders();
		throw;
	}

	cleanUpShaders();
}

Shader::~Shader() {
	glDeleteProgram(programId);
}

void Shader::useProgram() const {
	glUseProgram(getProgramId());
}

GLuint Shader::getProgramId() const noexcept {
	return programId;
}

std::string Shader::loadShaderCode(const std::filesystem::path& shaderPath) {
	std::ifstream file{shaderPath};
	if(!file.is_open()) {
		throw std::ios_base::failure{"std::ifstream failed to open \"" + shaderPath.string() + "\" file"};
	} else {
		file.exceptions(std::ios::failbit | std::ios::badbit);
	}

	const auto fileSize = static_cast<std::string::size_type>(std::filesystem::file_size(shaderPath));
	std::string content;
	content.reserve(fileSize);
	content.assign(std::istreambuf_iterator<char>{file}, std::istreambuf_iterator<char>{});
	return content;
}

GLuint Shader::compileShader(const std::string& shaderCode, GLenum shaderType) {
	const GLuint shaderId = glCreateShader(shaderType);
	const GLchar* const rawShaderCode = shaderCode.c_str();

	glShaderSource(shaderId, 1, &rawShaderCode, nullptr);
	glCompileShader(shaderId);

	GLint success = 0;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
	if(!success) {
		throw ShaderException{ShaderErrc::SHADER_COMPILATION, shaderId};
	}

	return shaderId;
}

void Shader::createProgram(GLuint vertexShaderId, GLuint fragmentShaderId) {
	programId = glCreateProgram();
	glAttachShader(programId, vertexShaderId);
	glAttachShader(programId, fragmentShaderId);
	glLinkProgram(programId);
	
	GLint success = 0;
	glGetProgramiv(programId, GL_LINK_STATUS, &success);
	if(!success) {
		throw ShaderException{ShaderErrc::SHADER_PROGRAM_LINKING, programId};
	}
}
