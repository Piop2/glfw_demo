cmake_minimum_required(VERSION 3.5.0)
project(opengl_demo VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(libs/glfw)

add_executable(opengl_demo
    src/main.cpp

    src/glad.c
)

target_link_libraries(opengl_demo PRIVATE glfw ${GLFW_LIBRARIES})
target_include_directories(opengl_demo PRIVATE lib/GLFW/include/GLFW)

target_include_directories(opengl_demo PRIVATE include/)
