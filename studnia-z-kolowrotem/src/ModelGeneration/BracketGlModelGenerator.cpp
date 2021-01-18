#include "BracketGlModelGenerator.h"

#include <glm/ext.hpp>

BracketGlModelGeneator::BracketGlModelGeneator(const WellModel& model)
    : basicModel{model}, sampleRate{DEFAULT_SAMPLE_RATE}, modelOffset{INVALID_MODEL_OFFSET} {
    setupVariables();
}

void BracketGlModelGeneator::setSampleRate(unsigned newSampleRate) {
    sampleRate = newSampleRate;
}

void BracketGlModelGeneator::setModelOffset(unsigned newModelOffset) {
    modelOffset = newModelOffset;
}

void BracketGlModelGeneator::setFinalTranslationVector(const glm::vec3& newTranslation) {
    translation = newTranslation;
}

unsigned BracketGlModelGeneator::getModelOffset() const {
    return 2 * sampleRate;
}

BracketGlModelGeneator::ModelPair BracketGlModelGeneator::generate() {
    if(modelOffset == INVALID_MODEL_OFFSET) {
        throw std::invalid_argument{"BracketGlModelGeneator: invalid model offset"};
    }

    setupVariables();
    createVertices();
    adjustModelOffset();
    translateModel();
    return ModelPair{std::move(vertices), std::move(indices)};
}

void BracketGlModelGeneator::setupVariables() {
    innerAngle = glm::radians(360.0f / sampleRate);
    lowerOffset = 0;
    higherOffset = lowerOffset + sampleRate;
}

void BracketGlModelGeneator::createVertices() {
    createLowerVertices();
    createHigherVertices();
    connectVertices();
}

void BracketGlModelGeneator::createLowerVertices() {
    glm::vec3 start{basicModel.getBracketRadius(), 0.0f, 0.0f};
    createCircleFrom(start);
}

void BracketGlModelGeneator::createHigherVertices() {
    glm::vec3 start{
        basicModel.getBracketRadius(),
        basicModel.getHeight() + basicModel.getBracketHeight(),
        0.0f
    };
    createCircleFrom(start);
}

void BracketGlModelGeneator::createCircleFrom(const glm::vec3& start) {
    glm::vec3 pattern = start;
    for(unsigned index = 0; index < sampleRate; ++index) {
        vertices.push_back(pattern);
        pattern = glm::rotateY(pattern, innerAngle);
    }
}

void BracketGlModelGeneator::connectVertices() {
    for(unsigned index = 0; index < sampleRate; ++index) {
        const unsigned next = nextIndex(index);

        indices.push_back(index + lowerOffset);
        indices.push_back(next + lowerOffset);
        indices.push_back(next + higherOffset);

        indices.push_back(index + lowerOffset);
        indices.push_back(index + higherOffset);
        indices.push_back(next + higherOffset);
    }
}

unsigned BracketGlModelGeneator::nextIndex(unsigned index) {
    ++index;
    if(index == sampleRate) {
        index = 0;
    }
    return index;
}

void BracketGlModelGeneator::adjustModelOffset() {
    for(unsigned& index : indices) {
        index += modelOffset;
    }
}

void BracketGlModelGeneator::translateModel() {
    const glm::mat4 transformation = glm::translate(translation);
    for(glm::vec3& vertex : vertices) {
        vertex = glm::vec3{transformation * glm::vec4{vertex, 1.0f}};
    }
}
