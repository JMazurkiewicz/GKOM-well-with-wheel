#include "KeyboardListener.h"

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
	for(KeyboardListener* listener : listeners) {
		if(listener->isListeningOn(window)) {
			listener->onPress(key);
		}
	}
}

void KeyboardListener::callOnRelease(GLFWwindow* window, int key) {
	for(KeyboardListener* listener : listeners) {
		if(listener->isListeningOn(window)) {
			listener->onRelease(key);
		}
	}
}
