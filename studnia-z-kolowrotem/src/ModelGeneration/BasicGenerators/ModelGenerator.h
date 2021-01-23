#pragma once

#include "Graphics/IndexGroup.h"
#include "Graphics/Vertex.h"
#include <vector>

class ModelGenerator {
public:
	using Vertices = std::vector<Vertex>;
	using Indices = std::vector<IndexGroup>;
	using Model = std::pair<Vertices, Indices>;

	ModelGenerator();
	ModelGenerator(const ModelGenerator&) = delete;
	ModelGenerator& operator=(const ModelGenerator&) = delete;
	ModelGenerator(ModelGenerator&&) noexcept = default;
	ModelGenerator& operator=(ModelGenerator&&) noexcept = default;

	virtual ~ModelGenerator() = default;

	void setArrayOffset(unsigned newArrayOffset);
	void setTransformation(const glm::mat4& newTransformation);

	[[nodiscard]] virtual unsigned getVertexCount() const = 0;
	[[nodiscard]] Model generateModel();

protected:
	virtual void finishModel() = 0;
	virtual void constructModel() = 0;
	
	void adjustArrayOffset();
	void applyTransformation();

	Vertices vertices;
	Indices indices;

	unsigned arrayOffset;
	glm::mat4 transformation;
};
