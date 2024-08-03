#if !defined(CALLBACKS_H)
#define CALLBACKS_H
#pragma once

#include <GLFW/glfw3.h>

void glfw_error_callback(int error, const char* description);

void glfw_window_close_callback(GLFWwindow* window);

#endif // defined