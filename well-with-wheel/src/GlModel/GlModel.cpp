#include "GlModel.h"

#include <algorithm>

GlModel::GlModel(Vertices&& vertices, Indices&& indices)
    : vertices{std::move(vertices)}, indices{std::move(indices)} { }

const GlModel::Vertices& GlModel::getVertices() const noexcept {
    return vertices;
}

const GlModel::Indices& GlModel::getIndices() const noexcept {
    return indices;
}

void GlModel::transform(const glm::mat4& transformation) {
    const auto transformPosition = [transformation](glm::vec3& pos) {
        pos = glm::vec3{transformation * glm::vec4{pos, 1.0f}};
    };

    std::ranges::for_each(vertices, transformPosition, &Vertex::position);
}
