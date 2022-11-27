#pragma once

#include "System/Window.h"

#include <unordered_set>

class ActionListener {
public:
    ActionListener() = default;
    virtual ~ActionListener() = default;

    ActionListener(const ActionListener&) = delete;
    ActionListener& operator=(const ActionListener&) = delete;

    void listenOn(Window& window);
    void stopListeningOn(Window& window);

protected:
    bool isListeningOn(GLFWwindow* windowHandle);

private:
    std::unordered_set<Window*> windows;
};
