#include "WellGlView.h"

#include "Model/WellGlModel.h"

WellGlView::WellGlView() : model{nullptr} {
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glGenBuffers(1, &nbo);
}

WellGlView::WellGlView(const WellGlModel& model) : WellGlView() {
	setModel(model);
}

WellGlView::~WellGlView() {
	glDeleteBuffers(1, &ebo);
	glDeleteBuffers(1, &vbo);
	glDeleteBuffers(1, &nbo);
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

	using Normals = WellGlModel::Normals;
	const Normals& normals = model->getNormals();
	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(Normals::value_type), normals.data(), GL_STATIC_DRAW);
}

void WellGlView::draw() {
	glEnable(GL_DEPTH_TEST);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, static_cast<void*>(0));

	glEnableVertexAttribArray(2);
	glBindBuffer(GL_ARRAY_BUFFER, nbo);
	glVertexAttribPointer(2, 3,	GL_FLOAT, GL_FALSE,	0, (void*)0);

	glDrawElements(GL_TRIANGLES, model->getIndices().size(), GL_UNSIGNED_INT, static_cast<void*>(0));

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
}

std::ostream& operator<<(std::ostream& stream, const WellGlView& view) {
	return stream << "[well-gl-view:" << &view << "]";
}
