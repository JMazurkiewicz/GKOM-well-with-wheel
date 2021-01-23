#pragma once

#include "KeyboardListener.h"
#include "Model/GlModel.h"

class WheelControler : public KeyboardListener {
public:
	void setModel(GlModel& wheelModel);
	void update();

protected:
	virtual void onKeyPress(int key) override;
	virtual void onKeyRelease(int key) override;

private:
	bool canUpdate() const;

	GlModel* model;

	bool expandKeyPressed = false;
	bool collapseKeyPressed = false;
};