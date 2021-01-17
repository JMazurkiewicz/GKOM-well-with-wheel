#include "MipmapTexture.h"

MipmapTexture::MipmapTexture()
	: handle{0} { }

MipmapTexture::MipmapTexture(GLuint id, const Image& image) : MipmapTexture() {
	glGenTextures(1, &handle);
	glActiveTexture(id);
	glBindTexture(GL_TEXTURE_2D, handle);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image.getWidth(),
		         image.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, image.getBytes());

	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
}

MipmapTexture::~MipmapTexture() {
	glDeleteTextures(1, &handle);
}

MipmapTexture::MipmapTexture(GLuint id, const std::string& path)
	: MipmapTexture(id, Image{path}) { }

MipmapTexture::MipmapTexture(GLuint id, const char* path)
	: MipmapTexture(id, Image{path}) { }

GLuint MipmapTexture::getHandle() const noexcept {
	return handle;
}
