#pragma once

#include <memory>
#include <SOIL.h>
#include <string>

class Image {
public:
	Image();
	explicit Image(const std::string& path);
	explicit Image(const char* path);

	Image(const Image&) = delete;
	Image& operator=(const Image&) = delete;

	const unsigned char* getBytes() const noexcept;

	int getWidth() const noexcept;
	int getHeight() const noexcept;

private:
	struct ImageDeleter {
		void operator()(unsigned char* image) const noexcept {
			SOIL_free_image_data(image);
		}
	};
	using ImageHandle = std::unique_ptr<unsigned char[], ImageDeleter>;

	ImageHandle handle;
	int width, height;
};