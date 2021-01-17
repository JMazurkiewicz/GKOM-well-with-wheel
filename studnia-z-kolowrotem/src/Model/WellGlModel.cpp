#include "WellGlModel.h"

WellGlModel::WellGlModel(Vertices&& vertices, Indices&& indices, Normals&& normals)
	: vertices{ std::move(vertices) }, indices{ std::move(indices) }, normals{ std::move(normals) } { }

const WellGlModel::Vertices& WellGlModel::getVertices() const {
	return vertices;
}

const WellGlModel::Indices& WellGlModel::getIndices() const {
	return indices;
}

const WellGlModel::Normals& WellGlModel::getNormals() const {
	return normals;
}
