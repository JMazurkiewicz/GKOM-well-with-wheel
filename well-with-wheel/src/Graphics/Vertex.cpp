#include "Vertex.h"

Vertex::Vertex()
    : position{}
    , color{}
    , texture{} { }

Vertex::Vertex(const glm::vec3& position)
    : position{position}
    , color{}
    , texture{} { }

Vertex::Vertex(float x, float y, float z)
    : position{x, y, z}
    , color{}
    , texture{} { }
