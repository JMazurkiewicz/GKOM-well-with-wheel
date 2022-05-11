cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project("GKOM-well-with-wheel")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(WWW_DIRECTORY well-with-wheel/src)

set(SOURCES

    ${WWW_DIRECTORY}/Controller/ActionListener.cpp
    ${WWW_DIRECTORY}/Controller/ActionListener.cpp
    ${WWW_DIRECTORY}/Controller/Camera.cpp
    ${WWW_DIRECTORY}/Controller/KeyboardListener.cpp
    ${WWW_DIRECTORY}/Controller/MouseListener.cpp
    ${WWW_DIRECTORY}/Controller/WheelController.cpp

    ${WWW_DIRECTORY}/GlModel/GlModel.cpp

    ${WWW_DIRECTORY}/Graphics/Texture.cpp
    ${WWW_DIRECTORY}/Graphics/Vertex.cpp

    ${WWW_DIRECTORY}/Graphics/Shader/GlProgram.cpp
    ${WWW_DIRECTORY}/Graphics/Shader/Shader.cpp
    ${WWW_DIRECTORY}/Graphics/Shader/ShaderException.cpp
    ${WWW_DIRECTORY}/Graphics/Shader/ShaderType.cpp

    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/ClosedCylinderGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/CompoundModelGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/CuboidGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/CylinderGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/HollowCylinderGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/ModelGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/PlaneGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/PrimitiveGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/BasicGenerators/SmoothShapeGenerator.cpp

    ${WWW_DIRECTORY}/ModelGeneration/WellGeneration/WellBaseGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/WellGeneration/WellRoofGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/WellGeneration/WheelGenerator.cpp
    ${WWW_DIRECTORY}/ModelGeneration/WellGeneration/WoodenStandGenerator.cpp

    ${WWW_DIRECTORY}/Startup/Environment.cpp
    ${WWW_DIRECTORY}/Startup/Main.cpp
    ${WWW_DIRECTORY}/Startup/MainWindow.cpp
    ${WWW_DIRECTORY}/Startup/Scene.cpp
    ${WWW_DIRECTORY}/Startup/Well.cpp

    ${WWW_DIRECTORY}/System/Stopwatch.cpp
    ${WWW_DIRECTORY}/System/Window.cpp

    ${WWW_DIRECTORY}/View/DynamicGlView.cpp
    ${WWW_DIRECTORY}/View/GlView.cpp
    ${WWW_DIRECTORY}/View/StaticGlView.cpp
)

add_executable(well-with-wheel ${SOURCES})
target_include_directories(well-with-wheel PUBLIC ${WWW_DIRECTORY})

if(UNIX)
    # Suppress 'compound assignment with ‘volatile’-qualified left operand is deprecated' warning from glm library
    target_compile_options(well-with-wheel PRIVATE "-Wno-volatile")
endif()

add_subdirectory(external/glfw EXCLUDE_FROM_ALL)
target_link_libraries(well-with-wheel PRIVATE glfw)

add_definitions(-DGLEW_STATIC)
add_subdirectory(external/glew EXCLUDE_FROM_ALL)
target_link_libraries(well-with-wheel PRIVATE libglew_static)

add_subdirectory(external/glm EXCLUDE_FROM_ALL)
target_link_libraries(well-with-wheel PRIVATE glm)
