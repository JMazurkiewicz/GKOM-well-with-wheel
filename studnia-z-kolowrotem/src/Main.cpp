#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Graphics/MipmapTexture.h"
#include "Graphics/Shader.h"
#include <iostream>
#include "LibraryExceptions/GlfwException.h"
#include "LibraryExceptions/SoilException.h"
#include <SOIL.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <typeinfo>
#include "System/Window.h"

using namespace std;

constexpr GLuint WIDTH = 800, HEIGHT = 600;

[[noreturn]] void throwGlfwException(int errorCode, const char* description) {
	throw GlfwException{errorCode, description};
}

int main() try {
	glfwSetErrorCallback(&throwGlfwException);
	glfwInit();

	Window window(WIDTH, HEIGHT, "GKOM - OpenGL 05");

	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		throw exception("GLEW Initialization failed");
	}

	glViewport(0, 0, WIDTH, HEIGHT);

	Shader shader{"gl_05.vert", "gl_05.frag"};

	// Set up vertex data 
	GLfloat vertices[] = {
		// coordinates			// color			// texture
		0.25f,  0.5f,  0.0f,	1.0f, 0.0f, 0.0f,	1.0f,  0.0f,
		-0.75f,  0.5f,  0.0f,	0.0f, 1.0f, 0.0f,	0.0f,  0.0f,
		-0.25f, -0.5f,  0.0f,	0.0f, 0.0f, 1.0f,	0.0f,  1.0f,
		0.75f, -0.5f,  0.0f,	1.0f, 0.0f, 1.0f,	1.0f,  1.0f,
	};

	GLuint indices[] = {
		0, 1, 2,
		0, 2, 3,
	};

	GLuint VBO, EBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// vertex geometry data
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	// vertex color data
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	// vertex texture coordinates
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0); // Note that this is allowed, the call to glVertexAttribPointer registered VBO as the currently bound vertex buffer object so afterwards we can safely unbind

	glBindVertexArray(0); // Unbind VAO (it's always a good thing to unbind any buffer/array to prevent strange bugs)

	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	// Set texture wrapping to GL_REPEAT (usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	MipmapTexture texture0(GL_TEXTURE0, "iipw.png");
	MipmapTexture texture1(GL_TEXTURE1, "weiti.png");

	while (!window.shouldClose()) {
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Clear the colorbuffer
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Bind Textures using texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture0.getHandle());
		glUniform1i(glGetUniformLocation(shader.getProgramId(), "Texture0"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture1.getHandle());
		glUniform1i(glGetUniformLocation(shader.getProgramId(), "Texture1"), 1);

		glm::mat4 trans;
		static GLfloat rot_angle = 0.0f;
		trans = glm::rotate(trans, -glm::radians(rot_angle), glm::vec3(1.0, 0.0, 0.0));
		rot_angle += 0.05f;
		if (rot_angle >= 360.0f)
			rot_angle -= 360.0f;
		GLuint transformLoc = glGetUniformLocation(shader.getProgramId(), "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(trans));

		shader.useProgram();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, std::size(indices), GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);

		window.swapBuffers();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);

	glfwTerminate();

} catch(GlfwException& e) {
	std::cerr << "GLFW exception occured:\n";
	std::cerr << "  what(): " << e.what() << '\n';
	std::cerr << "  code(): " << e.getErrorCode() << '\n';
} catch(SoilException& e) {
	std::cerr << "SOIL exception occured:\n";
	std::cerr << "  what(): " << e.what() << '\n';
} catch(std::exception& e) {
	std::cerr << "Unexpected error:\n";
	std::cerr << "  what(): " << e.what() << '\n';
	std::cerr << "  exception type name: " << typeid(e).name() << '\n';
} catch(...) {
	std::cerr << "Unexpected error...\n";
}