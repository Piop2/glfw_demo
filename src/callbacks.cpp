#include "callbacks.hpp"

#include "utilities.hpp"

void GLFWErrorCallback(int error, const char* description)
{
	write_log(description);
	throw("glfw error");
}

void GLFWWindowCloseCallback(GLFWwindow* window)
{
	write_log("window closed");
}
