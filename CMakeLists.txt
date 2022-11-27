cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(
    "GKOM-well-with-wheel"
    LANGUAGES CXX
    VERSION 0.3.0
    HOMEPAGE_URL https://github.com/JMazurkiewicz/GKOM-well-with-wheel
    DESCRIPTION "Well with wheel"
)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

set(ASSETS
    well-with-wheel/assets/shaders/main.frag
    well-with-wheel/assets/shaders/main.vert

    well-with-wheel/assets/textures/grass.dds
    well-with-wheel/assets/textures/plank.dds
    well-with-wheel/assets/textures/sky.dds
    well-with-wheel/assets/textures/stone.dds
    well-with-wheel/assets/textures/wood.dds
)

foreach(ASSET ${ASSETS})
    cmake_path(RELATIVE_PATH ASSET BASE_DIRECTORY well-with-wheel OUTPUT_VARIABLE ASSET_OUT)
    configure_file(${ASSET} ${CMAKE_BINARY_DIR}/${ASSET_OUT} COPYONLY)
    cmake_path(GET ASSET_OUT PARENT_PATH ASSET_INSTALL_PATH)
    install(FILES ${CMAKE_BINARY_DIR}/${ASSET_OUT} DESTINATION bin/${ASSET_INSTALL_PATH})
endforeach()

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
set_target_properties(well-with-wheel PROPERTIES CXX_EXTENSIONS OFF)

if(NOT EMSCRIPTEN)
    find_package(GLFW REQUIRED)
    find_package(GLEW REQUIRED)
    target_link_libraries(well-with-wheel PRIVATE glfw)
    target_link_libraries(well-with-wheel PRIVATE libglew_static)
else()
    set(WWW_LINK_OPTIONS
        "-sUSE_GLFW=3"
        "-sFETCH"
        "-fwasm-exceptions"
        "--preload-file" "assets"
        "-sFULL_ES3"
    )
    # FIXME clangd is unable to use sysroot directory
    # target_compile_options(well-with-wheel PUBLIC "--sysroot=${EMSCRIPTEN_SYSROOT}")
    # FIXME libc++ requires "-fexperimental-library" flag even in LLVM 15
    target_compile_options(well-with-wheel PRIVATE "-fwasm-exceptions" "-fexperimental-library")
    target_link_options(well-with-wheel PRIVATE ${WWW_LINK_OPTIONS})
    set_target_properties(well-with-wheel PROPERTIES SUFFIX ".html")
endif()

find_package(GLM REQUIRED)
target_link_libraries(well-with-wheel PRIVATE glm)

install(TARGETS well-with-wheel DESTINATION bin)
