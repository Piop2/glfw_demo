cmake_minimum_required(VERSION 3.5.0)
project(opengl_demo VERSION 0.1.0 LANGUAGES C CXX)

add_executable(opengl_demo
    main.cpp

    src/glad.c
)

