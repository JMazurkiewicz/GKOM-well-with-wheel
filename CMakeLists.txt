cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

project("GKOM-well-with-wheel")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(SOURCES

    well-with-wheel/src/Controler/ActionListener.cpp
    well-with-wheel/src/Controler/ActionListener.cpp
    well-with-wheel/src/Controler/Camera.cpp
    well-with-wheel/src/Controler/KeyboardListener.cpp
    well-with-wheel/src/Controler/MouseListener.cpp
    well-with-wheel/src/Controler/WheelControler.cpp

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

# Temporary solution
if(MSVC)
    add_definitions(/D__cpp_lib_ranges)
    add_definitions(/D__cpp_lib_format)
endif()

add_executable(well-with-wheel ${SOURCES})
target_include_directories(well-with-wheel PUBLIC ${PROJECT_SOURCE_DIR}/well-with-wheel/src)

add_subdirectory(external/glfw EXCLUDE_FROM_ALL)
target_link_libraries(well-with-wheel PRIVATE glfw)

add_definitions(-DGLEW_STATIC)
add_subdirectory(external/glew EXCLUDE_FROM_ALL)
target_link_libraries(well-with-wheel PRIVATE libglew_static)

add_subdirectory(external/glm EXCLUDE_FROM_ALL)
target_link_libraries(well-with-wheel PRIVATE glm)
