#include "GlView.h"

GlView::GlView() : model{nullptr} {
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
}

GlView::~GlView() {
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
}

void GlView::setModel(const GlModel& newModel) {	
	model = &newModel;
	updateModel();
}

void GlView::draw() {
	glEnable(GL_DEPTH_TEST);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, color)));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, texture)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElements(GL_TRIANGLES, 3 * model->getIndices().size(), GL_UNSIGNED_INT, static_cast<void*>(0));

	glDisableVertexAttribArray(3);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}
