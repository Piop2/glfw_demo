#include <cstdio>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "callbacks.hpp"
#include "utilities.hpp"

int main(int argc, char** argv){
	glfwSetErrorCallback(GLFWErrorCallback);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	GLFWwindow* window = glfwCreateWindow(800, 600, ExtractVersion(argv[0]), nullptr, nullptr);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	glfwSetWindowCloseCallback(window, GLFWWindowCloseCallback);

	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
