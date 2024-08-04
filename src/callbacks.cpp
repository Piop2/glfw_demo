#include "callbacks.hpp"

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
