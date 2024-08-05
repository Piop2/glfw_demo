cmake_minimum_required(VERSION 3.5.0)
project(opengl_demo VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)

add_executable(opengl_demo
    src/main.cpp
    src/callbacks.cpp
    src/utilities.cpp
    src/input.cpp
    src/rendering/gl/version.cpp
    src/rendering/gl/draw.cpp
    src/rendering/gl/mesh_loader.cpp
    src/rendering/gl/query_shader.cpp
    src/rendering/gl/shader_loader.cpp

    src/glad.c
)

target_include_directories(opengl_demo PRIVATE include/)

target_link_libraries(opengl_demo PRIVATE glfw ${GLFW_LIBRARIES})
target_include_directories(opengl_demo PRIVATE libs/GLFW/include/GLFW)

target_include_directories(opengl_demo PRIVATE libs/glm)
