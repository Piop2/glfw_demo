#include "callbacks.hpp"

#include <string>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "utilities.hpp"

void GLFWErrorCallback(int error, const char* description)
{
	WriteLog(description);
	throw("glfw error");
}

void GLFWWindowCloseCallback(GLFWwindow* window)
{
	WriteLog("window closed");
}

void GLFWFramebufferSizeCallback(GLFWwindow* window, int w, int h)
{
	std::string the_log = "window size changed to: " + std::to_string(w) + "x" + std::to_string(h);
	WriteLog(the_log.c_str());
	glViewport(0, 0, w, h);
}
