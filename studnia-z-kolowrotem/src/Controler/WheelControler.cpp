#include "WheelControler.h"

#include <iostream> // temp

namespace {
	static constexpr int COLLAPSE_KEY = GLFW_KEY_RIGHT;
	static constexpr int EXPAND_KEY = GLFW_KEY_LEFT;
}

void WheelControler::setModel(GlModel& wheelModel) {
	model = &wheelModel;
}

void WheelControler::update() {
	if(canUpdate()) {
		if(expandKeyPressed) {
			std::cout << "ROZWINIÊCIE\n";
		} else if(collapseKeyPressed) {
			std::cout << "ZWINIÊCIE\n";
		}
	}
}

void WheelControler::onKeyPress(int key) {
	switch(key) {
	case EXPAND_KEY:
		expandKeyPressed = true;
		break;
	case COLLAPSE_KEY:
		collapseKeyPressed = true;
		break;
	}
}

void WheelControler::onKeyRelease(int key) {
	switch(key) {
	case EXPAND_KEY:
		expandKeyPressed = false;
		break;
	case COLLAPSE_KEY:
		collapseKeyPressed = false;
		break;
	}
}

bool WheelControler::canUpdate() const {
	return !(expandKeyPressed && collapseKeyPressed) && model != nullptr;
}
