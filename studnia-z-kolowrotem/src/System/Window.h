#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
public:
	enum Style : unsigned int {
		NONE = 0,
		RESIZABLE = 1 << 0,
		FULLSCREEN = 1 << 1
	};

	explicit Window(int width, int height, const char* title, Style style = NONE);
	~Window();
	
	Window(const Window&) = delete;
	Window& operator=(const Window&) = delete;

	int getWidth() const noexcept;
	int getHeight() const noexcept;
	GLFWwindow* getHandle() const;

	float getAspectRatio() const;

	void makeContextCurrent();
	void swapBuffers();
	bool shouldClose() const;

private:
	void registerCallbacks();

	int width;
	int height;
	GLFWwindow* handle;
};
