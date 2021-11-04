#include "Texture.h"

#include <algorithm>
#include <array>
#include <bit>
#include <fstream>
#include <limits>
#include <vector>

namespace {
    constexpr unsigned FOURCC_DXT1 = 0x31545844;
    constexpr unsigned FOURCC_DXT3 = 0x33545844;
    constexpr unsigned FOURCC_DXT5 = 0x35545844;

    constexpr std::array<char, 4> FILE_CODE = {'D', 'D', 'S', ' '};
}

Texture::~Texture() {
    destroy();
}

void Texture::loadTexture(const char* path) {
    destroy();

    std::ifstream file{path, std::ios::binary};
    if(!file.is_open()) {
        throw std::ios_base::failure{"Texture: failed to open file"};
    }

    std::array<char, 4> fileCode;
    file.read(fileCode.data(), fileCode.size());
    if(fileCode != FILE_CODE) {
        throw std::invalid_argument{"Texture: invalid file code"};
    }

    std::array<unsigned char, 124> header;
    file.read(std::bit_cast<char*>(header.data()), header.size());

    unsigned height = *std::bit_cast<unsigned int*>(&header[8]);
    unsigned width = *std::bit_cast<unsigned int*>(&header[12]);

    const unsigned linearSize = *std::bit_cast<unsigned*>(&header[16]);
    const unsigned mipMapCount = *std::bit_cast<unsigned*>(&header[24]);
    const unsigned fourCC = *std::bit_cast<unsigned*>(&header[80]);

    const std::size_t bufferSize = mipMapCount > 1 ? linearSize * 2 : linearSize;
    std::vector<unsigned char> buffer(bufferSize);

    file.read(std::bit_cast<char*>(buffer.data()), buffer.size());

    const unsigned int format = [fourCC] {
        switch(fourCC) {
        case FOURCC_DXT1:
            return GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        case FOURCC_DXT3:
            return GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        case FOURCC_DXT5:
            return GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        default:
            throw std::invalid_argument{"Texture: unrecogised file type"};
        }
    }();

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    const unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;

    for(unsigned int level = 0, offset = 0; level < mipMapCount && (width || height); ++level) {
        const unsigned int size = ((width + 3) / 4) * ((height + 3) / 4) * blockSize;

        glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height, 0, size, buffer.data() + offset);
        offset += size;

        width = std::ranges::clamp(width / 2u, 1u, std::numeric_limits<unsigned>::max());
        height = std::ranges::clamp(height / 2u, 1u, std::numeric_limits<unsigned>::max());
    }
}

void Texture::destroy() {
    if(texture != 0) {
        glDeleteTextures(1, &texture);
        texture = 0;
    }
}
