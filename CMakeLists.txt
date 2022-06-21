cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(
    "GKOM-well-with-wheel"
    LANGUAGES CXX
    VERSION 0.2.0
    HOMEPAGE_URL https://github.com/JMazurkiewicz/GKOM-well-with-wheel
    DESCRIPTION "Well with wheel"
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_executable(well-with-wheel

    well-with-wheel/src/Controller/ActionListener.cpp
    well-with-wheel/src/Controller/ActionListener.cpp
    well-with-wheel/src/Controller/Camera.cpp
    well-with-wheel/src/Controller/KeyboardListener.cpp
    well-with-wheel/src/Controller/MouseListener.cpp
    well-with-wheel/src/Controller/WheelController.cpp

    well-with-wheel/src/GlModel/GlModel.cpp

    well-with-wheel/src/Graphics/Texture.cpp
    well-with-wheel/src/Graphics/Vertex.cpp

    well-with-wheel/src/Graphics/Shader/GlProgram.cpp
    well-with-wheel/src/Graphics/Shader/Shader.cpp
    well-with-wheel/src/Graphics/Shader/ShaderException.cpp
    well-with-wheel/src/Graphics/Shader/ShaderType.cpp

    well-with-wheel/src/ModelGeneration/BasicGenerators/ClosedCylinderGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/CompoundModelGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/CuboidGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/CylinderGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/HollowCylinderGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/ModelGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/PlaneGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/PrimitiveGenerator.cpp
    well-with-wheel/src/ModelGeneration/BasicGenerators/SmoothShapeGenerator.cpp

    well-with-wheel/src/ModelGeneration/WellGeneration/WellBaseGenerator.cpp
    well-with-wheel/src/ModelGeneration/WellGeneration/WellRoofGenerator.cpp
    well-with-wheel/src/ModelGeneration/WellGeneration/WheelGenerator.cpp
    well-with-wheel/src/ModelGeneration/WellGeneration/WoodenStandGenerator.cpp

    well-with-wheel/src/Startup/Environment.cpp
    well-with-wheel/src/Startup/Main.cpp
    well-with-wheel/src/Startup/MainWindow.cpp
    well-with-wheel/src/Startup/Scene.cpp
    well-with-wheel/src/Startup/Well.cpp

    well-with-wheel/src/System/Stopwatch.cpp
    well-with-wheel/src/System/Window.cpp

    well-with-wheel/src/View/DynamicGlView.cpp
    well-with-wheel/src/View/GlView.cpp
    well-with-wheel/src/View/StaticGlView.cpp
)

target_include_directories(well-with-wheel PUBLIC well-with-wheel/src)
target_compile_features(well-with-wheel PUBLIC cxx_std_20)

find_package(glfw REQUIRED)
target_link_libraries(well-with-wheel PRIVATE glfw)

find_package(glew REQUIRED)
target_link_libraries(well-with-wheel PRIVATE libglew_static)

find_package(glm REQUIRED)
target_link_libraries(well-with-wheel PRIVATE glm)

# Workaround: use clang with libc++ (libstdc++'s ranges are broken on clang)
if(UNIX AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(well-with-wheel PUBLIC "-stdlib=libc++")
endif()
