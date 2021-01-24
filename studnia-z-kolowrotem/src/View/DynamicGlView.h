#pragma once

#include "GlView.h"

class DynamicGlView : public GlView {
public:
	using GlView::GlView;

	void updateView();

protected:
	void updateModel() override;
};