cmake_minimum_required(VERSION 3.5.0)
project(opengl_demo VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(lib/glfw)
add_subdirectory(lib/glm)
add_library(glad lib/glad/glad.c)

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
)

target_include_directories(opengl_demo PRIVATE 
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/lib/GLFW/include/GLFW
    ${PROJECT_SOURCE_DIR}/lib/glm
)

target_link_libraries(opengl_demo PRIVATE
    glfw
    ${GLFW_LIBRARIES}
)

set(ASSET_DIR ${CMAKE_SOURCE_DIR}/asset/)
set(ASSET_DIR_OUT $<TARGET_FILE_DIR:opengl_demo>/asset)
add_custom_command(TARGET opengl_demo POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${ASSET_DIR} ${ASSET_DIR_OUT}
)