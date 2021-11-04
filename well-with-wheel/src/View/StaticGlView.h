#pragma once

#include "GlView.h"

class StaticGlView : public GlView {
public:
    using GlView::GlView;

protected:
    void updateModel() override;
};