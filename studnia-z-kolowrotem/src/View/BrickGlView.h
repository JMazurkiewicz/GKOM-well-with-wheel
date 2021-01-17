#pragma once

#include <GL/glew.h>
#include <memory>

class BrickGlModel;

class BrickGlView {
public:
	BrickGlView();
	explicit BrickGlView(const BrickGlModel& model);
	~BrickGlView();

	BrickGlView(const BrickGlView&) = delete;
	BrickGlView& operator=(const BrickGlView&) = delete;

	void setModel(const BrickGlModel& newModel);
	void draw() const;

	friend std::ostream& operator<<(std::ostream& stream, const BrickGlView& view);

private:
	const BrickGlModel* model;

	GLuint buffer;
	GLuint elementBuffer;
};
