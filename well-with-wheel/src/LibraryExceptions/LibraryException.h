#pragma once

#include <stdexcept>

class LibraryException : public std::runtime_error {
public:
	using runtime_error::runtime_error;
};