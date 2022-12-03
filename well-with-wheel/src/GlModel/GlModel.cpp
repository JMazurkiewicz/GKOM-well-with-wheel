#include "GlModel.h"

GlModel::GlModel(Vertices&& vertices, Indices&& indices)
    : vertices{std::move(vertices)}
    , indices{std::move(indices)} { }

const GlModel::Vertices& GlModel::getVertices() const noexcept {
    return vertices;
}

const GlModel::Indices& GlModel::getIndices() const noexcept {
    return indices;
}

void GlModel::transform(const glm::mat4& transformation) {
    for(Vertex& vertex : vertices) {
        vertex.position = glm::vec3{
            transformation * glm::vec4{vertex.position, 1.0f}
        };
    }
}
