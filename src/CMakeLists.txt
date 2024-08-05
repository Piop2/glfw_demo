add_executable(opengl_demo
    main.cpp
    callbacks.cpp
    utilities.cpp
    input.cpp
    rendering/gl/version.cpp
    rendering/gl/draw.cpp
    rendering/gl/mesh_loader.cpp
    rendering/gl/query_shader.cpp
    rendering/gl/shader_loader.cpp

    glad.c
)

target_include_directories(opengl_demo PRIVATE ../include/)

target_link_libraries(opengl_demo PRIVATE glfw ${GLFW_LIBRARIES})
target_include_directories(opengl_demo PRIVATE ../libs/GLFW/include/GLFW)

target_include_directories(opengl_demo PRIVATE ../libs/glm)

