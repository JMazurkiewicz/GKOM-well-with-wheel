#pragma once

#include "LibraryException.h"

class GlfwException : public LibraryException {
public:
	GlfwException(int errorCode, const std::string& description);
	GlfwException(int errorCode, const char* description);

	int getErrorCode() const noexcept;

private:
	const int errorCode;
};