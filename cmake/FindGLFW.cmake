include(FetchContent)

message(STATUS "Looking for GLFW")
find_package(glfw 3.3.7 QUIET CONFIG)

if(glfw_FOUND)
    message(STATUS "Found GLFW: ${glfw_DIR} (found version \"${glfw_VERSION}\")")
else()
    message(STATUS "GLFW not found - handling with FetchContent")
    FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
        GIT_TAG 3.3.7
    )

    if(NOT glfw)
        FetchContent_Populate(glfw)
        add_subdirectory(${glfw_SOURCE_DIR} EXCLUDE_FROM_ALL)
    endif()
endif()
