#include "EnvironmentGlView.h"

#include "Model/EnvironmentGlModel.h"

EnvironmentGlView::EnvironmentGlView() : model{nullptr} {
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
}

EnvironmentGlView::EnvironmentGlView(const EnvironmentGlModel& model) : EnvironmentGlView() {
	setModel(model);
}

EnvironmentGlView::~EnvironmentGlView() {
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
}

void EnvironmentGlView::setModel(const EnvironmentGlModel& newModel) {
	model = &newModel;

	using Vertices = EnvironmentGlModel::Vertices;
	const Vertices& vertices = model->getVertices();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertices::value_type), vertices.data(), GL_STATIC_DRAW);

	using Indices = EnvironmentGlModel::Indices;
	const Indices& indices = model->getIndices();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Indices::value_type), indices.data(), GL_STATIC_DRAW);
}

void EnvironmentGlView::draw() {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElements(GL_TRIANGLES, model->getIndices().size(), GL_UNSIGNED_INT, static_cast<void*>(0));
	glDisableVertexAttribArray(0);
}
