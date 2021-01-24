#pragma once

#include <set>
#include "System/Window.h"

class ActionListener {
public:
	ActionListener() = default;
	ActionListener(const ActionListener&) = delete;
	ActionListener& operator=(const ActionListener&) = delete;
	virtual ~ActionListener() = default;

	void listenOn(Window& window);
	void stopListeningOn(Window& window);

protected:
	bool isListeningOn(GLFWwindow* window);

private:
	std::set<Window*> windows;
};