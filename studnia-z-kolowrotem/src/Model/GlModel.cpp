#include "GlModel.h"

GlModel::GlModel(Vertices&& vertices, Indices&& indices)
    : vertices{std::move(vertices)}, indices{std::move(indices)} { }

const GlModel::Vertices& GlModel::getVertices() const noexcept {
    return vertices;
}

const GlModel::Indices& GlModel::getIndices() const noexcept {
    return indices;
}
