#include "EnvironmentGlModelGenerator.h"

#include "Model/EnvironmentModel.h"

EnvironmentGlModelGenerator::EnvironmentGlModelGenerator(const EnvironmentModel& basicModel)
	: basicModel{basicModel} { }

GlModel EnvironmentGlModelGenerator::generate() {
	const float size = basicModel.getSize();
	vertices.emplace_back(-size, 0.0f, -size);
	vertices.emplace_back(-size, 0.0f, +size);
	vertices.emplace_back(+size, 0.0f, +size);
	vertices.emplace_back(+size, 0.0f, -size);

	vertices[0].texture = glm::vec2(0, 1);
	vertices[1].texture = glm::vec2(0, 0);
	vertices[2].texture = glm::vec2(1, 0);
	vertices[3].texture = glm::vec2(1, 1);

	indices.push_back({0, 2, 1});
	indices.push_back({0, 3, 2});
	return GlModel{std::move(vertices), std::move(indices)};
}
