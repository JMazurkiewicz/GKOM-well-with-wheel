#pragma once

#include "Graphics/IndexGroup.h"
#include "Graphics/Vertex.h"

#include <vector>

class GlModel {
public:
    using Vertices = std::vector<Vertex>;
    using Indices = std::vector<IndexGroup>;

    GlModel() = default;
    explicit GlModel(Vertices&& vertices, Indices&& indices);

    GlModel(const GlModel&) = delete;
    GlModel& operator=(const GlModel&) = delete;
    GlModel(GlModel&&) = default;
    GlModel& operator=(GlModel&&) = default;

    const Vertices& getVertices() const noexcept;
    const Indices& getIndices() const noexcept;

    void transform(const glm::mat4& transformation);

protected:
    Vertices vertices;
    Indices indices;
};
