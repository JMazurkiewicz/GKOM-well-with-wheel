#pragma once

#include <memory>

class BrickGlModel;

class BrickGlView {
public:
	BrickGlView();
	explicit BrickGlView(const BrickGlModel& model);
	~BrickGlView();

	BrickGlView(BrickGlView&&) = default;
	BrickGlView& operator=(BrickGlView&&) = default;

	void setModel(const BrickGlModel& newModel);
	void draw() const;

private:
	struct State;
	std::unique_ptr<State> state;
};
