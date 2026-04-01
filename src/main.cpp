#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <scout.hpp>


int main() {
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Scout Engine", nullptr, nullptr);
	
	if (window == NULL) {
		std::cerr << "Failed to create window.\n";
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
		std::cerr << "Failed to load OpenGL.\n";
		glfwTerminate();
		return 1;
	}

	glViewport(0, 0, 800, 600);

	while (!glfwWindowShouldClose(window)) {
		
		glfwPollEvents();

		glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;

}
