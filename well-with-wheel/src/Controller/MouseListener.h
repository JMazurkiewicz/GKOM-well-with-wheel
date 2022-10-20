#pragma once

#include "ActionListener.h"

#include <unordered_set>

class MouseListener : public virtual ActionListener {
public:
    MouseListener();
    ~MouseListener() override;

    static void callback(GLFWwindow* window, double xpos, double ypos);

protected:
    virtual void onCursorMove(double x, double y) = 0;

    static std::unordered_set<MouseListener*> listeners;
};
