#if !defined(OPENGLDEMO_CALLBACKS_H)
#define OPENGLDEMO_CALLBACKS_H
#pragma once

#include <GLFW/glfw3.h>

void GLFWErrorCallback(int error, const char* description);

void GLFWWindowCloseCallback(GLFWwindow* window);

#endif // OPENGLDEMO_CALLBACKS_H