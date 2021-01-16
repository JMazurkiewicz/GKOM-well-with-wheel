#include <filesystem>
#include <iostream>
#include "LibraryExceptions/SoilException.h"
#include <typeinfo>

#include "Application.h"
#include "MainWindow.h"

namespace filesystem = std::filesystem;

int main() try {
	std::ios_base::sync_with_stdio(false);
	std::cerr.tie(nullptr);
	
	if(!glfwInit()) {
		std::cerr << "glfw initialization failed\n";
		return EXIT_FAILURE;
	}

#ifndef NDEBUG
	glfwSetErrorCallback([](int code, const char* info) {
		std::cerr << "[glfw:" << code << "] " << info << '\n';
	});
#endif

	MainWindow window;
	glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		std::cerr << "glew initialization failed\n";
		return EXIT_FAILURE;
	}

	std::cerr << "program info:\n"
		         "  current path: " << filesystem::current_path() << '\n';

	Application application{window};
	application.run();

	glfwTerminate();

#if 0 // exclude this code
	Shader shader{"gl_05.vert", "gl_05.frag"};

	GLfloat vertices[] = {
		0.25f,  0.5f,  0.0f,	1.0f, 0.5f, 0.0f,	1.0f,  0.0f,
		-0.75f,  0.5f,  0.0f,	0.0f, 1.0f, 0.4f,	0.0f,  0.0f,
		-0.25f, -0.5f,  0.0f,	0.0f, 0.2f, 1.0f,	0.0f,  1.0f,
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
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

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

	//MipmapTexture texture0(GL_TEXTURE0, "iipw.png");
	//MipmapTexture texture1(GL_TEXTURE1, "weiti.png");

	while (!window.shouldClose()) {
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();

		// Clear the colorbuffer
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Bind Textures using texture units
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, texture0.getHandle());
		//glUniform1i(glGetUniformLocation(shader.getProgramId(), "Texture0"), 0);
		//glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, texture1.getHandle());
		//glUniform1i(glGetUniformLocation(shader.getProgramId(), "Texture1"), 1);

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
#endif

} catch(SoilException& e) {
	std::cerr << "SOIL exception occured:\n"
	             "  what(): " << e.what() << '\n';
	return EXIT_FAILURE;
} catch(std::exception& e) {
	std::cerr << "Unexpected error:\n"
	             "  what(): \"" << e.what() << "\"\n"
	             "  exception type name: \"" << typeid(e).name() << "\"\n";
	return EXIT_FAILURE;
} catch(...) {
	std::cerr << "Unexpected error...\n";
	return EXIT_FAILURE;
}
