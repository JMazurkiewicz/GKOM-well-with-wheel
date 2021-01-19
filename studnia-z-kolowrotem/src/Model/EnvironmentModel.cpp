#include "EnvironmentModel.h"

EnvironmentModel::EnvironmentModel()
    : size{DEFAULT_SIZE} { }

float EnvironmentModel::getSize() const noexcept {
    return size;
}

void EnvironmentModel::setSize(float newSize) {
    size = newSize;
}

bool EnvironmentModel::validateModel() const {
    return size > 0.0f;
}
