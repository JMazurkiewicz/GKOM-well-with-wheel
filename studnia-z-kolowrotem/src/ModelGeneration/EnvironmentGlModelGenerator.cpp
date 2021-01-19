#include "EnvironmentGlModelGenerator.h"

#include "Model/EnvironmentModel.h"

EnvironmentGlModelGenerator::EnvironmentGlModelGenerator(const EnvironmentModel& basicModel)
	: basicModel{basicModel} { }

EnvironmentGlModel EnvironmentGlModelGenerator::generate() {
	const float size = basicModel.getSize();
	vertices.emplace_back(-size, 0.0f, -size);
	vertices.emplace_back(-size, 0.0f, +size);
	vertices.emplace_back(+size, 0.0f, +size);
	vertices.emplace_back(+size, 0.0f, -size);

	indices = {0, 2, 1, 0, 3, 2};
	return EnvironmentGlModel{std::move(vertices), std::move(indices)};
}
