#include "ShaderType.h"

ShaderType getShaderType(const std::filesystem::path& path) {
    const auto extension = path.extension();

    using enum ShaderType;
    if(extension == ".vert") {
        return VERTEX;
    } else if(extension == ".frag") {
        return FRAGMENT;
    } else {
        return UNKNOWN;
    }
}
