#pragma once

#include <GL/glew.h>

class Texture {
public:
	Texture() = default;
	~Texture();

	Texture(const Texture&) = delete;
	Texture& operator=(const Texture&) = delete;

	void loadTexture(const char* path);

private:
	void destroy();

	GLuint texture = 0;
};
