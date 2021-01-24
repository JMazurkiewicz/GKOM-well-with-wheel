#include "KeyboardListener.h"

std::mutex KeyboardListener::mutex;
std::set<KeyboardListener*> KeyboardListener::listeners;

KeyboardListener::KeyboardListener() {
	listeners.insert(this);
}

KeyboardListener::~KeyboardListener() {
	listeners.erase(this);
}

void KeyboardListener::callback(GLFWwindow* window, int key, int scanCode, int action, int mode) {
	switch(action) {
	case GLFW_PRESS:
		callOnPress(window, key);
		break;
	case GLFW_RELEASE:
		callOnRelease(window, key);
		break;
	}
}

void KeyboardListener::callOnPress(GLFWwindow* window, int key) {
	std::lock_guard guard{mutex};
	for(KeyboardListener* listener : listeners) {
		if(listener->isListeningOn(window)) {
			listener->onKeyPress(key);
		}
	}
}

void KeyboardListener::callOnRelease(GLFWwindow* window, int key) {
	std::lock_guard guard{mutex};
	for(KeyboardListener* listener : listeners) {
		if(listener->isListeningOn(window)) {
			listener->onKeyRelease(key);
		}
	}
}
