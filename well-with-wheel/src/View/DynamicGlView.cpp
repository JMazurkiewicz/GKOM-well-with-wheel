#include "DynamicGlView.h"

void DynamicGlView::updateView() {
    updateModel();
}

void DynamicGlView::updateModel() {
    using Vertices = GlModel::Vertices;
    const Vertices& vertices = model->getVertices();
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertices::value_type), vertices.data(), GL_DYNAMIC_DRAW);

    using Indices = GlModel::Indices;
    const Indices& indices = model->getIndices();
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(Indices::value_type), indices.data(),
                 GL_DYNAMIC_DRAW);
}
