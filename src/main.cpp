#include <cstdio>

#include <fstream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "callbacks.hpp"
#include "utilities.hpp"
#include "input.hpp"
#include "rendering/gl/version.hpp"
#include "rendering/gl/draw.hpp"
#include "rendering/gl/vertex.hpp"
#include "rendering/gl/query_shader.hpp"
#include "rendering/gl/mesh_loader.hpp"
#include "rendering/gl/shader_loader.hpp"

int main(int argc, char** argv){
	glfwSetErrorCallback(GLFWErrorCallback);
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, ExtractProgramName(argv[0]), nullptr, nullptr);
	glfwMakeContextCurrent(window);
	gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
	printGLinfo();

	glfwSetWindowCloseCallback(window, GLFWWindowCloseCallback);
	glfwSetFramebufferSizeCallback(window, GLFWFramebufferSizeCallback);

	std::string vertshader = ReadToString("./asset/glsl/vertex_shader.glsl");
	std::string fragshader = ReadToString("./asset/glsl/fragment_shader.glsl");

	unsigned int mainShader = LoadShader(vertshader.c_str(), fragshader.c_str());
	glClearColor(.3f, .3f, .9f, 0.f);
	std::vector<DrawDetails> ourDrawDetails;

	const float posData[] = {
		-0.8f, -0.8f, 0.0f,
		0.8f, -0.8f, 0.0f,
		0.0f, 0.8f, 0.0f
	};
	const float colorData[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f
	};
	const GLuint elems[] = { 0, 1, 2 };
	ourDrawDetails.push_back(UploadMesh(posData, colorData, sizeof(posData) / sizeof(posData[0]),
		elems, sizeof(elems) / sizeof(elems[0])));

	//std::default_random_engine generator;
	//std::uniform_real_distribution<float> distribution(0.f, 1.f);

	QueryInputAttribs(mainShader);
	QueryUniforms(mainShader);

	double prev_time = glfwGetTime();
	while (!glfwWindowShouldClose(window)) {
		double current_time = glfwGetTime();
		double dt = current_time - prev_time;
		prev_time = current_time;
		//std::cout << "dt = " << dt << '\n';
		// HANDLE KEYPRESS
		ProcessInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(mainShader);
		glm::mat4 finalModelMatrix = glm::mat4(1);
		finalModelMatrix = glm::translate(finalModelMatrix, glm::vec3(sin((float)glfwGetTime()) / 2, cos((float)glfwGetTime()) / 2, 0));
		finalModelMatrix = glm::rotate(finalModelMatrix, (float)glfwGetTime(), glm::vec3(0.f, 1.f, 0.f));
		finalModelMatrix = glm::scale(finalModelMatrix, glm::vec3(.5));
		GLuint location = glGetUniformLocation(mainShader, "uModelMatrix");
		glUniformMatrix4fv(location, 1, GL_FALSE, &finalModelMatrix[0][0]);
		for (const auto& thing : ourDrawDetails) {
		Draw(ourDrawDetails);
		}


		//float c1 = distribution(generator);
		//float c2 = distribution(generator);
		//float c3 = distribution(generator);
		//uint32_t var = glGetUniformLocation(mainShader, "ucolor");
		//glUniform3f(var, c1, c2, c3);

		// RENDER OUR OBJECT
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// UNLOAD DATA FROM GRAPHICS CARD
	UnloadMesh(ourDrawDetails);

	glfwTerminate();
	return 0;
}
