#pragma once

#include "ActionListener.h"
#include <mutex>
#include <set>

class KeyboardListener : public virtual ActionListener {
public:
	KeyboardListener();
	~KeyboardListener() override;

	static void callback(GLFWwindow* window, int key, int scanCode, int action, int mode);

protected:
	virtual void onKeyPress(int key) = 0;
	virtual void onKeyRelease(int key) = 0;

	static void callOnPress(GLFWwindow* window, int key);
	static void callOnRelease(GLFWwindow* window, int key);

	static std::set<KeyboardListener*> listeners;
	static std::mutex mutex;
};