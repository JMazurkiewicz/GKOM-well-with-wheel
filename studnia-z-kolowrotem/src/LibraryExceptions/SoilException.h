#pragma once

#include "LibraryException.h"

class SoilException : public LibraryException {
public:
	SoilException();
	using LibraryException::LibraryException;
};