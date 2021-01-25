
#include "CuboidGenerator.h"

CuboidGenerator::CuboidGenerator()
	: length{1.0f}, width{1.0f}, height{1.0f} { }

void CuboidGenerator::setLength(float newLength) {
	length = newLength;
}

void CuboidGenerator::setWidth(float newWidth) {
	width = newWidth;
}

void CuboidGenerator::setHeight(float newHeight) {
	height = newHeight;
}

unsigned CuboidGenerator::getVertexCount() const {
	return 24;
}

void CuboidGenerator::constructModel() {
	constructVertices();
	connectVertices();
	createNormals();
}

void CuboidGenerator::createTexCoords() {
	for(unsigned rect = 0; rect < 6; rect++) {
		unsigned idx1 = 4 * rect;
		unsigned idx2 = idx1 + 1;
		unsigned idx3 = idx1 + 2;
		unsigned idx4 = idx1 + 3;

		vertices[idx1].texture = glm::vec2(1, 1);
		vertices[idx2].texture = glm::vec2(0, 1);
		vertices[idx3].texture = glm::vec2(0, 0);
		vertices[idx4].texture = glm::vec2(1, 0);

	}
}

void CuboidGenerator::constructVertices() {
	const float halfX = width / 2.0f;
	const float halfZ = length / 2.0f;

	vertices = {
		/*0*/glm::vec3{halfX, 0.0f, -halfZ},	/*0*/
		/*1*/glm::vec3{-halfX, 0.0f, -halfZ},	/*1*/
		/*2*/glm::vec3{-halfX, 0.0f, halfZ},	/*2*/
		/*3*/glm::vec3{halfX, 0.0f, halfZ},		/*3*/
												
		/*4*/glm::vec3{halfX, height, -halfZ},	/*4*/
		/*5*/glm::vec3{-halfX, height, -halfZ},	/*5*/
		/*6*/glm::vec3{-halfX, height, halfZ},	/*6*/
		/*7*/glm::vec3{halfX, height, halfZ},	/*7*/
												
		/*5*/glm::vec3{-halfX, height, -halfZ},	/*8*/
		/*1*/glm::vec3{-halfX, 0.0f, -halfZ},	/*9*/
		/*2*/glm::vec3{-halfX, 0.0f, halfZ},	/*10*/
		/*6*/glm::vec3{-halfX, height, halfZ},	/*11*/
												
		/*0*/glm::vec3{halfX, 0.0f, -halfZ},	/*12*/
		/*4*/glm::vec3{halfX, height, -halfZ},	/*13*/
		/*7*/glm::vec3{halfX, height, halfZ},	/*14*/
		/*3*/glm::vec3{halfX, 0.0f, halfZ},		/*15*/
												
		/*7*/glm::vec3{halfX, height, halfZ},	/*16*/
		/*6*/glm::vec3{-halfX, height, halfZ},	/*17*/
		/*2*/glm::vec3{-halfX, 0.0f, halfZ},	/*18*/
		/*3*/glm::vec3{halfX, 0.0f, halfZ},		/*19*/
												
		/*5*/glm::vec3{-halfX, height, -halfZ},	/*20*/
		/*4*/glm::vec3{halfX, height, -halfZ},	/*21*/
		/*0*/glm::vec3{halfX, 0.0f, -halfZ},	/*22*/
		/*1*/glm::vec3{-halfX, 0.0f, -halfZ}	/*23*/
	};
}

void CuboidGenerator::connectVertices() {

	for (unsigned rect = 0; rect < 6; rect++) {
		unsigned idx1 = 4*rect;
		unsigned idx2 = idx1 + 1;
		unsigned idx3 = idx1 + 2;
		unsigned idx4 = idx1 + 3;

		indices.push_back({ idx1, idx2, idx3 });
		indices.push_back({ idx1, idx4, idx3 });

	}
}

void CuboidGenerator::createNormals() {
	for (unsigned rect = 0; rect < 6; rect++) {
		unsigned idx1 = 4 * rect;
		unsigned idx2 = idx1 + 1;
		unsigned idx3 = idx1 + 2;
		unsigned idx4 = idx1 + 3;

		glm::vec3 normal;

		switch (rect) {
		case 0:
			normal = glm::vec3(0, -1, 0);
			break;
		case 1:
			normal = glm::vec3(0, 1, 0);
			break;
		case 2:
			normal = glm::vec3(-1, 0, 0);
			break;
		case 3:
			normal = glm::vec3(1, 0, 0);
			break;
		case 4:
			normal = glm::vec3(1, 0, 0);
			break;
		case 5:
			normal = glm::vec3(-1, 0, 0);
			break;
		default:
			normal = glm::vec3(1, 1, 1);
		}

		vertices[idx1].normal = normal;
		vertices[idx2].normal = normal;
		vertices[idx3].normal = normal;
		vertices[idx4].normal = normal;
	}
}
