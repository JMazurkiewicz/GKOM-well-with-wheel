include(FetchContent)

message(STATUS "Looking for GLEW")
find_package(libglew_static 2.1.0 QUIET CONFIG)

if(libglew_static_FOUND)
    message(STATUS "Found GLEW: ${libglew_static_DIR} (found version \"${libglew_static_VERSION}\")")
else()
    message(STATUS "GLEW not found - handling with FetchContent")
    FetchContent_Declare(
        libglew_static
        GIT_REPOSITORY https://github.com/omniavinco/glew-cmake
        GIT_TAG glew-cmake-2.1.0
    )

    if(NOT libglew_static_POPULATED)
        FetchContent_Populate(libglew_static)
        add_subdirectory(${libglew_static_SOURCE_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()

target_compile_definitions(libglew_static PRIVATE GLEW_STATIC)
