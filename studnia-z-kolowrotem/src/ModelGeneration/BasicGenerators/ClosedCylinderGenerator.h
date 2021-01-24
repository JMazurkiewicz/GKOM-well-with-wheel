#pragma once

#include "CylinderGenerator.h"

class ClosedCylinderGenerator : public CylinderGenerator {
public:
	using CylinderGenerator::CylinderGenerator;

private:
	void constructModel() override;
	void createConnections();

	unsigned nextIndex(unsigned index);
};