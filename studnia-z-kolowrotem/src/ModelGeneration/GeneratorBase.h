#pragma once

#include <glm/glm.hpp>
#include "Model/GlModel.h"
#include <tuple>
#include <vector>

class GeneratorBase {
public:
	using Vertices = std::vector<glm::vec3>;
	using Indices = std::vector<unsigned>;
	using Model = std::tuple<Vertices, Indices>;

	GeneratorBase();
	GeneratorBase(const GeneratorBase&) = delete;
	GeneratorBase& operator=(const GeneratorBase&) = delete;

	virtual ~GeneratorBase() = default;

	void setArrayOffset(unsigned newArrayOffset);
	void setTransformation(const glm::mat4& newTransformation);

	[[nodiscard]] virtual unsigned getVertexCount() const = 0;
	[[nodiscard]] Model generateModel();

protected:
	virtual void constructModel() = 0;

	Vertices vertices;
	Indices indices;

private:
	void applyTransformation();
	void adjustArrayOffset();

	unsigned arrayOffset;
	glm::mat4 transformation;
};
