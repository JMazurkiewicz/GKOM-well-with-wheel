#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>


class Texture {

public:

	void loadTexture(const char* imagepath);
	~Texture();

private:
	GLuint texture = 0;

	void destroy();
};

