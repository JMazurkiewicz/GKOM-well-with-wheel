#pragma once

#include "GlModel/GlModel.h"
#include "KeyboardListener.h"
#include "Model/WellModel.h"
#include "View/DynamicGlView.h"

class WheelController : public KeyboardListener {
public:
    static constexpr float DEFAULT_SPEED = 5.0f;

    explicit WheelController(const WellModel& basicModel);

    void setModel(GlModel& wheelModel);
    void setView(DynamicGlView& wheelView);
    void setSpeed(float newSpeed);

    void update(float time);

protected:
    virtual void onKeyPress(int key) override;
    virtual void onKeyRelease(int key) override;

private:
    bool canUpdate() const;

    const WellModel& basicModel;

    GlModel* model = nullptr;
    DynamicGlView* view = nullptr;

    float speed = DEFAULT_SPEED;

    bool expandKeyPressed = false;
    bool collapseKeyPressed = false;
};
