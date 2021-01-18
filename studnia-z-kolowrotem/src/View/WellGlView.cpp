#include "WellGlView.h"

#include "Model/WellGlModel.h"

WellGlView::WellGlView() : model{nullptr} {
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
}

WellGlView::WellGlView(const WellGlModel& model) : WellGlView() {
	setModel(model);
}

WellGlView::~WellGlView() {
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
}

void WellGlView::setModel(const WellGlModel& newModel) {
	model = &newModel;

	using Vertices = WellGlModel::Vertices;
	const Vertices& vertices = model->getVertices();
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertices::value_type), vertices.data(), GL_STATIC_DRAW);

	using Indices = WellGlModel::Indices;
	const Indices& indices = model->getIndices();
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Indices::value_type), indices.data(), GL_STATIC_DRAW);
}

void WellGlView::draw() {
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElements(GL_TRIANGLES, model->getIndices().size(), GL_UNSIGNED_INT, static_cast<void*>(0));
	glDisableVertexAttribArray(0);
}

std::ostream& operator<<(std::ostream& stream, const WellGlView& view) {
	return stream << "[well-gl-view:" << &view << "]";
}
