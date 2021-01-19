#include "EnvironmentGlModel.h"

EnvironmentGlModel::EnvironmentGlModel(Vertices&& vertices, Indices&& indices)
    : vertices{std::move(vertices)}, indices{std::move(indices)} { }

const EnvironmentGlModel::Vertices& EnvironmentGlModel::getVertices() const noexcept {
    return vertices;
}

const EnvironmentGlModel::Indices& EnvironmentGlModel::getIndices() const noexcept {
    return indices;
}
