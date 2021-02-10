#include "ActionListener.h"

#include <algorithm>

void ActionListener::listenOn(Window& window) {
	windows.insert(&window);
}

void ActionListener::stopListeningOn(Window& window) {
	windows.erase(&window);
}

bool ActionListener::isListeningOn(GLFWwindow* windowHandle) {
	return std::ranges::find(windows, windowHandle, &Window::getHandle) != windows.end();
}
