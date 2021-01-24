#include "MouseListener.h"

std::set<MouseListener*> MouseListener::listeners;
std::mutex MouseListener::mutex;

MouseListener::MouseListener() {
	listeners.insert(this);
}

MouseListener::~MouseListener() {
	listeners.erase(this);
}

void MouseListener::callback(GLFWwindow* window, double x, double y) {
	std::lock_guard guard{mutex};
	for(MouseListener* listener : listeners) {
		if(listener->isListeningOn(window)) {
			listener->onCursorMove(x, y);
		}
	}
}
