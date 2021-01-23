#include "ActionListener.h"

#include <algorithm>

void ActionListener::listenOn(Window& window) {
	windows.insert(&window);
}

void ActionListener::stopListeningOn(Window& window) {
	windows.erase(&window);
}

bool ActionListener::isListeningOn(GLFWwindow* window) {
	const auto compare = [window](Window* windowPtr) {
		return window == windowPtr->getHandle();
	};

	return std::find_if(windows.begin(), windows.end(), compare) != windows.end();
}
