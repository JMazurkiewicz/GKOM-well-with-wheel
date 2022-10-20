#include "Scene.h"

#include "Graphics/Shader/Shader.h"

#include <glm/ext.hpp>

Scene::Scene(MainWindow& window)
    : window{window}
    , vao{0}
    , camera{window}
    , well{window} {
    glGenVertexArrays(1, &vao);
}

Scene::~Scene() {
    glDeleteVertexArrays(1, &vao);
}

void Scene::start() {
    prepareShader();
    GLint MatrixID = mainProgram.getUniformLocation("MVP");
    GLint ViewMatrixID = mainProgram.getUniformLocation("V");
    GLint ModelMatrixID = mainProgram.getUniformLocation("M");
    GLint LightID = mainProgram.getUniformLocation("LightPosWorld");

    do {
        glfwPollEvents();
        clear();

        glBindVertexArray(vao);
        mainProgram.use();
        updateCamera(MatrixID, ViewMatrixID, ModelMatrixID);
        glUniform3f(LightID, 0.0f, 0.2f, 0.0f);
        update();
        glBindVertexArray(0);

        window.swapBuffers();
    } while(!shouldClose());
}

void Scene::prepareShader() {
    Shader vertexShader{"assets/shaders/main.vert"};
    mainProgram.attachShader(vertexShader);

    Shader fragmentShader{"assets/shaders/main.frag"};
    mainProgram.attachShader(fragmentShader);

    mainProgram.link();
}

void Scene::clear() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Scene::update() {
    environment.update();
    well.update();
}

void Scene::updateCamera(GLint& MatrixID, GLint& ModelMatrixID, GLint& ViewMatrixID) {
    camera.update();
    const glm::mat4 viewMatrix = camera.getViewMatrix();
    const glm::mat4 modelMatrix = camera.getModelMatrix();
    const glm::mat4 cameraMatrix = camera.getMVP();

    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(cameraMatrix));
    glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, glm::value_ptr(modelMatrix));
    glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, glm::value_ptr(viewMatrix));
}

bool Scene::shouldClose() const {
    return glfwGetKey(window.getHandle(), GLFW_KEY_ESCAPE) == GLFW_PRESS || window.shouldClose();
}
