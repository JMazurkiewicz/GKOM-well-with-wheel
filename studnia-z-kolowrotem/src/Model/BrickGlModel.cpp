#include "BrickGlModel.h"

BrickGlModel::BrickGlModel() : vertices{} { }

const BrickGlModel::VertexArray& BrickGlModel::getVertexArray() const {
	return vertices;
}

std::ostream& operator<<(std::ostream& stream, const BrickGlModel& model) {
	stream << "[brick-model:" << &model << "]:\n";
	for(const glm::vec3& vertex : model.vertices) {
		stream << "  {" << vertex.x << ", " << vertex.y << ", " << vertex.z << "}\n";
	}
	return stream;
}
