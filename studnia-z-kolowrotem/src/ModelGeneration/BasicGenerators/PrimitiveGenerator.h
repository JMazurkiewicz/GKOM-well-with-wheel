#pragma once

#include "ModelGenerator.h"

class PrimitiveGenerator : public ModelGenerator {
public:
	PrimitiveGenerator() = default;
	PrimitiveGenerator(const PrimitiveGenerator&) = delete;
	PrimitiveGenerator operator=(const PrimitiveGenerator&) = delete;

private:
	void finishModel() override;
	virtual void createNormals();
};
