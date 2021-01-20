#include "WellGlModel.h"

WellGlModel::WellGlModel(Vertices&& vertices, Indices&& indices)
	: vertices{std::move(vertices)}, indices{std::move(indices)} { }

const WellGlModel::Vertices& WellGlModel::getVertices() const {
	return vertices;
}

const WellGlModel::Indices& WellGlModel::getIndices() const {
	return indices;
}
