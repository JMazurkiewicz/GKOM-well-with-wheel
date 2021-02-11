#include <SOIL.h>
#include "SoilException.h"

SoilException::SoilException() : LibraryException(SOIL_last_result()) { }