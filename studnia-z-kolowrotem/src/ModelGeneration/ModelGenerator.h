#pragma once

#include "Graphics/Vertex.h"
#include "Model/GlModel.h"
#include <tuple>
#include <vector>

class ModelGenerator {
public:
	using Vertices = std::vector<Vertex>;
	using Indices = std::vector<unsigned>;
	using Model = std::tuple<Vertices, Indices>;

	ModelGenerator();
	ModelGenerator(const ModelGenerator&) = delete;
	ModelGenerator& operator=(const ModelGenerator&) = delete;

	virtual ~ModelGenerator() = default;

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
