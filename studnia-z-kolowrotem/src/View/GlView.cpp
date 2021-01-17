#include "GlView.h"

GlView::GlView() : model{nullptr} {
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
}

GlView::GlView(const GlModel& model) : GlView() {
	setModel(model);
}

GlView::~GlView() {
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
}

void GlView::setModel(const GlModel& newModel) {
	model = &newModel;

	auto& vertices = model->getVertices();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(
		GL_ARRAY_BUFFER,
		vertices.size() * sizeof(GlModel::Vertices::value_type),
		vertices.data(),
		GL_STATIC_DRAW
	);

	auto& indices = model->getIndices();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(
		GL_ELEMENT_ARRAY_BUFFER,
		indices.size() * sizeof(GlModel::Indices::value_type), 
		indices.data(),
		GL_STATIC_DRAW
	);
}

void GlView::draw() {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElements(GL_TRIANGLES, model->getIndices().size(), GL_UNSIGNED_INT, static_cast<void*>(0));
	glDisableVertexAttribArray(0);
}
