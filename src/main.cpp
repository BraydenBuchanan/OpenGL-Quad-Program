#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>

#include "Renderer.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include <filesystem> 

int main(void) {
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(500, 500, "OpenGL", nullptr, nullptr);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cerr << "Error!\n";

	std::cout << glGetString(GL_VERSION) << "\n";

	{
		float vertices[] = {
			-0.5f, -0.5f,
			0.5f, -0.5f,
			0.5f, 0.5f,
			-0.5f, 0.5f
		};

		unsigned int indices[] = {
			0, 1, 2, 2, 3, 0
		};

		unsigned int VAO;
		GLCall(glGenVertexArrays(1, &VAO));
		GLCall(glBindVertexArray(VAO));

		VertexArray vertexArray;
		VertexBuffer vertexBuffer(vertices, sizeof(vertices));

		VertexBufferLayout layout;
		layout.Push<float>(2);
		vertexArray.AddBuffer(vertexBuffer, layout);

		IndexBuffer indexBuffer(indices, 6);

		Shader shader((std::filesystem::current_path().string()) + "/Shader.glsl");
		shader.Bind();
		shader.SetUniform4f("u_Color", 0.f, 0.f, 0.f, 1.f);
		shader.Unbind();

		float r = 0.f;
		float increment = 0.05f;

		while (!glfwWindowShouldClose(window)) {
			float timeVal = glfwGetTime();
			float greenPulseVal = (cos(timeVal) / 2.f) + 0.5f;

			shader.Bind();

			shader.SetUniform4f("u_Color", 0.f, greenPulseVal, 0.f, 1.f);
			Renderer::Result(vertexArray, indexBuffer, shader);

			GLCall(glfwSwapBuffers(window));
			GLCall(glfwPollEvents());
		}
	}
	glfwTerminate();
	return 0;
	
}