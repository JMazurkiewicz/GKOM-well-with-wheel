#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <GL/glew.h>

#include <GLFW/glfw3.h>


class Texture {

public:

	GLuint loadTexture(const char* imagepath);


private:

	GLuint texture;


};

