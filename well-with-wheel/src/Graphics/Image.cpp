#include "Image.h"
#include "LibraryExceptions/SoilException.h"

Image::Image() : handle{nullptr}, width{0}, height{0} { }

Image::Image(const std::string& path)
	: Image(path.c_str()) { }

Image::Image(const char* path) : Image() {
	unsigned char* rawHandle = SOIL_load_image(path, &width, &height, 0, SOIL_LOAD_RGB);
	if(rawHandle == nullptr) {
		throw SoilException{};
	}

	handle.reset(rawHandle);
}

const unsigned char* Image::getBytes() const noexcept {
	return handle.get();
}

int Image::getWidth() const noexcept {
	return width;
}

int Image::getHeight() const noexcept {
	return height;
}
