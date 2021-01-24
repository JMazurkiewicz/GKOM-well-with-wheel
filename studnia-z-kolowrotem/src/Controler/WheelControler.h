#pragma once

#include "KeyboardListener.h"
#include "GlModel/GlModel.h"
#include "View/GlView.h"

class WheelControler : public KeyboardListener {
public:
	static constexpr float SPEED = 5.0f / 1000.0f;

	void setModel(GlModel& wheelModel);
	void setView(GlView& wheelView);

	void update(float time);

protected:
	virtual void onKeyPress(int key) override;
	virtual void onKeyRelease(int key) override;

private:
	bool canUpdate() const;

	GlModel* model = nullptr;
	GlView* view = nullptr;

	bool expandKeyPressed = false;
	bool collapseKeyPressed = false;
};