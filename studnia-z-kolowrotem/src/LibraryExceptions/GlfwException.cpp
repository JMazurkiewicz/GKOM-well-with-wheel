#include "GlfwException.h"

GlfwException::GlfwException(int errorCode, const std::string& description)
	: GlfwException(errorCode, description.c_str()) { }

GlfwException::GlfwException(int errorCode, const char* description)
	: LibraryException(description), errorCode{errorCode} { }

int GlfwException::getErrorCode() const noexcept {
	return errorCode;
}
