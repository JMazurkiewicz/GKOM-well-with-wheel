#pragma once

#include "CylinderGenerator.h"

class ClosedCylinderGenerator : public CylinderGenerator {
public:
    using CylinderGenerator::CylinderGenerator;

private:
    void createIndices() override;
    void createConnections();
};
