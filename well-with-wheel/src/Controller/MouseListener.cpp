#include "MouseListener.h"

std::unordered_set<MouseListener*> MouseListener::listeners;

MouseListener::MouseListener() {
    listeners.insert(this);
}

MouseListener::~MouseListener() {
    listeners.erase(this);
}

void MouseListener::callback(GLFWwindow* window, double x, double y) {
    for(MouseListener* listener : listeners) {
        if(listener->isListeningOn(window)) {
            listener->onCursorMove(x, y);
        }
    }
}
