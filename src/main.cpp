#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <scout.hpp>
#include <window.hpp>


int main() {

	glfwInit();
	
	Scout::Window window("Test Window", 800, 600);
	
	while (window.isOpen()) {
		window.pollEvents();
	}

	window.close();
	
	glfwTerminate();

	return 0;

}
