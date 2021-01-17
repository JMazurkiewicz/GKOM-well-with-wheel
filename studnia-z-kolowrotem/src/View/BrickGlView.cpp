#include "BrickGlView.h"

#include "Model/BrickGlModel.h"

BrickGlView::BrickGlView() : model{nullptr}, buffer{0}, elementBuffer{0} {
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);

	glGenBuffers(1, &elementBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);
}

BrickGlView::BrickGlView(const BrickGlModel& model) : BrickGlView() {
	setModel(model);
}

BrickGlView::~BrickGlView() {
	glDeleteBuffers(1, &elementBuffer);
	glDeleteBuffers(1, &buffer);
}

void BrickGlView::setModel(const BrickGlModel& newModel) {
	model = &newModel;

	auto& vertices = model->getVertexArray();
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * vertices.size(), vertices.data(), GL_STATIC_DRAW);

	auto& indices = BrickGlModel::INDEX_ARRAY;
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * indices.size(), indices.data(), GL_STATIC_DRAW);
}

void BrickGlView::draw() const {
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementBuffer);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawElements(GL_TRIANGLES, BrickGlModel::INDEX_ARRAY.size(), GL_UNSIGNED_INT, nullptr);
	glDisableVertexAttribArray(0);
}

std::ostream& operator<<(std::ostream& stream, const BrickGlView& view) {
	return stream << "[brick-view:" << &view << "] -> [brick-model:" << view.model << "]\n";
}
