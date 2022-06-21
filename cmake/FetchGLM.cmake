include(FetchContent)

message(STATUS "Looking for GLM")
find_package(glm 0.9.7 QUIET)
if(glm_FOUND)
    message(STATUS "Found GLM: ${glm_DIR} (found version \"${glm_VERSION}\")")
else()
    message(STATUS "GLM not found - handling with FetchContent")
    FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm
        GIT_TAG 0.9.7.0
    )

    if(NOT glm_POPULATED)
        FetchContent_Populate(glm)
        add_subdirectory(${glm_SOURCE_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_compile_options(glm INTERFACE "-Wno-volatile")
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_compile_options(
        glm INTERFACE
        "-Wno-documentation"
        "-Wno-extra-semi-stmt"
        "-Wno-deprecated-volatile"
        "-Wno-reserved-identifier"
        "-Wno-reserved-macro-identifier"
    )
endif()
