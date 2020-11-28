#pragma once

#include <GL/glew.h>
#include "Image.h"

class MipmapTexture {
public:
	MipmapTexture();
	explicit MipmapTexture(GLuint id, const Image& image);

	explicit MipmapTexture(GLuint id, const std::string& path);
	explicit MipmapTexture(GLuint id, const char* path);

	MipmapTexture(const MipmapTexture&) = delete;
	MipmapTexture& operator=(const MipmapTexture&) = delete;

	GLuint getHandle() const noexcept;

private:
	GLuint handle;
};