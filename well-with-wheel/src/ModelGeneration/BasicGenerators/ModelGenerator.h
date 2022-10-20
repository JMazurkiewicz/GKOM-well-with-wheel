#pragma once

#include "GlModel/GlModel.h"

#include <vector>

class ModelGenerator {
public:
    using Vertices = GlModel::Vertices;
    using Indices = GlModel::Indices;

    ModelGenerator() = default;
    virtual ~ModelGenerator() = default;

    ModelGenerator(const ModelGenerator&) = delete;
    ModelGenerator& operator=(const ModelGenerator&) = delete;
    ModelGenerator(ModelGenerator&&) noexcept = default;
    ModelGenerator& operator=(ModelGenerator&&) noexcept = default;

    void setArrayOffset(unsigned newArrayOffset);
    void setTransformation(const glm::mat4& newTransformation);

    [[nodiscard]] virtual unsigned getVertexCount() const = 0;
    [[nodiscard]] GlModel generateModel();

protected:
    virtual void constructModel() = 0;

    Vertices vertices;
    Indices indices;

    void adjustArrayOffset();
    void applyTransformation();

private:
    unsigned arrayOffset = 0;
    glm::mat4 transformation = glm::mat4{1.0f};
};
