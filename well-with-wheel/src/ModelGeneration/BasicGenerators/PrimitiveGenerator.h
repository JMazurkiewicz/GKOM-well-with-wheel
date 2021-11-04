#pragma once

#include "ModelGenerator.h"

class PrimitiveGenerator : public ModelGenerator {
public:
    using ModelGenerator::ModelGenerator;

protected:
    virtual void createVertices() = 0;
    virtual void createIndices() = 0;
    virtual void createTexCoords() = 0;

private:
    void constructModel() override final;
};
