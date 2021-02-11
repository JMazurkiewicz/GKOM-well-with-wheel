#include "ShaderException.h"
#include <vector>

ShaderException::ShaderException(ShaderErrc code, GLuint associatedId)
	: LibraryException(getInfoLog(code, associatedId)),
	  code{code}, associatedId{associatedId} {}

GLuint ShaderException::getAssociatedId() const noexcept {
	return associatedId;
}

const char* ShaderException::getSituation() const noexcept {
	switch(code) {
	case ShaderErrc::SHADER_COMPILATION:
		return "Shader compilation";
	case ShaderErrc::SHADER_PROGRAM_LINKING:
		return "Shader program linking";
	default:
		return "Unknown situation";
	}
}

std::string ShaderException::getInfoLog(ShaderErrc code, GLuint associatedId) {
	switch(code) {
	case ShaderErrc::SHADER_COMPILATION:
		return getShaderInfoLog(associatedId);
	case ShaderErrc::SHADER_PROGRAM_LINKING:
		return getProgramInfoLog(associatedId);
	default:
		return "Unknown shader error";
	}
}

std::string ShaderException::getShaderInfoLog(GLuint shaderId) {
	GLint logLength = 0;
	glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &logLength);
	if(logLength == 0) {
		return "no info available";
	}

	std::vector<char> log(logLength);
	glGetShaderInfoLog(shaderId, log.size(), nullptr, log.data());
	return log.data();
}

std::string ShaderException::getProgramInfoLog(GLuint programId) {
	GLint logLength = 0;
	glGetShaderiv(programId, GL_INFO_LOG_LENGTH, &logLength);
	if(logLength == 0) {
		return "no info available";
	}

	std::vector<char> log(logLength);
	glGetShaderInfoLog(programId, log.size(), nullptr, log.data());
	return log.data();
}
