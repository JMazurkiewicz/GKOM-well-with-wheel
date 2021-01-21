#include "PrimitiveGenerator.h"

void PrimitiveGenerator::finishModel() {
	applyTransformation();
	createNormals();
	adjustArrayOffset();
}

void PrimitiveGenerator::createNormals() {
	//for(unsigned int index = 0; index < indices.size(); index += 3) {
	//	const unsigned _1 = indices[index];
	//	const unsigned _2 = indices[index + 1];
	//	const unsigned _3 = indices[index + 2];

	//	const glm::vec3 a = vertices[_1].position;
	//	const glm::vec3 b = vertices[_2].position;
	//	const glm::vec3 c = vertices[_3].position;

	//	const glm::vec3 vec = glm::cross(b - a, c - a);

	//	vertices[_1].normal += vec;
	//	vertices[_2].normal += vec;
	//	vertices[_3].normal += vec;
	//}

	//for(Vertex& vertex : vertices) {
 //		vertex.normal = glm::normalize(vertex.normal);
	//	auto& normal = vertex.normal;
	//}
}