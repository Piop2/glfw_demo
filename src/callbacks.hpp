#if !defined(OPENGLDEMO_CALLBACKS_H)
#define OPENGLDEMO_CALLBACKS_H
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void GLFWErrorCallback(int error, const char* description);

void GLFWWindowCloseCallback(GLFWwindow* window);

void GLFWFramebufferSizeCallback(GLFWwindow* window, int w, int h);

#endif // OPENGLDEMO_CALLBACKS_H