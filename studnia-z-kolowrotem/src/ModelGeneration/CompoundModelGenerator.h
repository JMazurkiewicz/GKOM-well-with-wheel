#pragma once

#include "ModelGenerator.h"
#include <vector>

class CompoundModelGenerator : public ModelGenerator {
public:
	CompoundModelGenerator();
	CompoundModelGenerator(const CompoundModelGenerator&) = delete;
	CompoundModelGenerator& operator=(const CompoundModelGenerator&) = delete;

	void addGenerator(ModelGenerator* generator);

	[[nodiscard]] unsigned getVertexCount() const;

private:
	void constructModel() override final;

	unsigned offset;
	std::vector<ModelGenerator*> generators;
};