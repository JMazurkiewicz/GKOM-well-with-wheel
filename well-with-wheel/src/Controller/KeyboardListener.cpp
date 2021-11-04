#include "KeyboardListener.h"

std::unordered_set<KeyboardListener*> KeyboardListener::listeners;

KeyboardListener::KeyboardListener() {
    listeners.insert(this);
}

KeyboardListener::~KeyboardListener() {
    listeners.erase(this);
}

void KeyboardListener::callback(GLFWwindow* windowHandle, int key, [[maybe_unused]] int scanCode, int action,
                                [[maybe_unused]] int mode) {
    switch(action) {
    case GLFW_PRESS:
        callOnPress(windowHandle, key);
        break;
    case GLFW_RELEASE:
        callOnRelease(windowHandle, key);
        break;
    }
}

void KeyboardListener::callOnPress(GLFWwindow* windowHandle, int key) {
    for(KeyboardListener* listener : listeners) {
        if(listener->isListeningOn(windowHandle)) {
            listener->onKeyPress(key);
        }
    }
}

void KeyboardListener::callOnRelease(GLFWwindow* window, int key) {
    for(KeyboardListener* listener : listeners) {
        if(listener->isListeningOn(window)) {
            listener->onKeyRelease(key);
        }
    }
}
