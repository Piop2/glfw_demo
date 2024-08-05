cmake_minimum_required(VERSION 3.5.0)
project(opengl_demo VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(libs/glfw)
add_subdirectory(libs/glm)

add_subdirectory(src)
