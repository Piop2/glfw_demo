#include "callbacks.hpp"

#include "utilities.hpp"

void glfw_error_callback(int error, const char* description)
{
	write_log(description);
	throw("glfw error");
}

void glfw_window_close_callback(GLFWwindow* window)
{
	write_log("window closed");
}
