#include "Environment.h"

#include "ModelGeneration/BasicGenerators/CylinderGenerator.h"
#include "ModelGeneration/BasicGenerators/PlaneGenerator.h"

Environment::Environment() {
    create();
}

void Environment::update() {
    Texture texture;
    texture.loadTexture("assets/textures/grass.dds");
    grassView.draw();

    texture.loadTexture("assets/textures/sky.dds");
    landscapeView.draw();
}

void Environment::create() {
    createGrass();
    createLandscape();
}

void Environment::createGrass() {
    PlaneGenerator grassGenerator;
    grassGenerator.setLength(basicModel.getSize());
    grassGenerator.setWidth(basicModel.getSize());
    grassModel = grassGenerator.generateModel();
    grassView.setModel(grassModel);
}

void Environment::createLandscape() {
    CylinderGenerator landscapeGenerator;
    landscapeGenerator.setHeight(basicModel.getHeight());
    landscapeGenerator.setRadius(basicModel.getSize() / 2.0f);
    landscapeModel = landscapeGenerator.generateModel();
    landscapeView.setModel(landscapeModel);
}
