#pragma once

#include "ActionListener.h"
#include <set>

class MouseListener : public virtual ActionListener {
public:
	MouseListener();
	~MouseListener() override;

	static void callback(GLFWwindow* window, double xpos, double ypos);

protected:
	virtual void onMove(double x, double y) = 0;

	static std::set<MouseListener*> listeners;
};