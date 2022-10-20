#pragma once

#include "ModelGenerator.h"

#include <vector>

class CompoundModelGenerator : public ModelGenerator {
public:
    using ModelGenerator::ModelGenerator;

    void addGenerator(ModelGenerator& generator);

    [[nodiscard]] unsigned getVertexCount() const override final;

protected:
    virtual void prepareGenerators() = 0;

private:
    void constructModel() override final;

    std::vector<ModelGenerator*> generators;
};
