#pragma once

#include "ModelGenerator.h"
#include <vector>

class CompoundModelGenerator : public ModelGenerator {
public:
	CompoundModelGenerator() = default;
	CompoundModelGenerator(const CompoundModelGenerator&) = delete;
	CompoundModelGenerator& operator=(const CompoundModelGenerator&) = delete;

	void addGenerator(ModelGenerator* generator);

	[[nodiscard]] unsigned getVertexCount() const;

protected:
	virtual void prepareGenerators() = 0;

private:
	void constructModel() override final;
	void finishModel() override final;

	std::vector<ModelGenerator*> generators;
};