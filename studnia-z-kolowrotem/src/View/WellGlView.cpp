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
	glEnable(GL_DEPTH_TEST);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, position)));
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, color)));

	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, normal)));

	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), reinterpret_cast<void*>(offsetof(Vertex, texture)));

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glDrawElements(GL_TRIANGLES, model->getIndices().size(), GL_UNSIGNED_INT, static_cast<void*>(0));

	glDisableVertexAttribArray(3);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);
}
