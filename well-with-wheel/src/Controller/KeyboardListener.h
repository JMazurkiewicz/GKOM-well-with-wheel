#pragma once

#include "ActionListener.h"

#include <unordered_set>

class KeyboardListener : public virtual ActionListener {
public:
    KeyboardListener();
    ~KeyboardListener() override;

    static void callback(GLFWwindow* windowHandle, int key, int scanCode, int action, int mode);

protected:
    virtual void onKeyPress(int key) = 0;
    virtual void onKeyRelease(int key) = 0;

    static void callOnPress(GLFWwindow* windowHandle, int key);
    static void callOnRelease(GLFWwindow* windowHandle, int key);

    static std::unordered_set<KeyboardListener*> listeners;
};
