#include "WheelControler.h"

#include <glm/ext.hpp>
#include "System/Stopwatch.h"

#if 1 // @TODO ROZWI¥ZANIE TYMCZASOWE
#include <iostream>
#include "Model/WellModel.h"
const glm::vec3 translationVector{WellModel::DEFAULT_INNER_RADIUS, WellModel::DEFAULT_WHEEL_HEIGHT, 0.0f};
#endif // END

namespace {
	static constexpr int COLLAPSE_KEY = GLFW_KEY_RIGHT;
	static constexpr int EXPAND_KEY = GLFW_KEY_LEFT;
}

void WheelControler::setModel(GlModel& wheelModel) {
	model = &wheelModel;
}

void WheelControler::setView(GlView& wheelView) {
	view = &wheelView;
}

void WheelControler::update(float time) {
	if(canUpdate()) {
		
		float angle = SPEED * time;

		if(expandKeyPressed) {
			// nothing??
			std::cout << "EXPAND\n";
		} else if(collapseKeyPressed) {
			std::cout << "COLLAPSE\n";
			angle = -angle;
		}

		const auto translation = glm::translate(-translationVector);
		const auto rotation = glm::rotate(angle, glm::vec3{1.0f, 0.0f, 0.0f});
		const auto translationBack = glm::translate(translationVector);

		model->transform(translationBack * rotation * translation);
		view->update();
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
	return
		expandKeyPressed != collapseKeyPressed &&
		model != nullptr &&
		view != nullptr;
}
