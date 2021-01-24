#pragma once

#include "KeyboardListener.h"
#include "GlModel/GlModel.h"
#include "View/GlView.h"

class WheelControler : public KeyboardListener {
public:
	static constexpr float DEFAULT_SPEED = 5.0f / 1000.0f;

	void setModel(GlModel& wheelModel);
	void setView(GlView& wheelView);
	void setSpeed(float newSpeed);

	void update(float time);

protected:
	virtual void onKeyPress(int key) override;
	virtual void onKeyRelease(int key) override;

private:
	bool canUpdate() const;

	GlModel* model = nullptr;
	GlView* view = nullptr;

	float speed = DEFAULT_SPEED;

	bool expandKeyPressed = false;
	bool collapseKeyPressed = false;
};