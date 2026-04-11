#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <scout.hpp>
#include <window.hpp>
#include <draw.hpp>


int main() {

	glfwInit();
	
	Scout::Window window("Test Window", 800, 600);
	
	Scout::Renderer::VertexArray vertexArray({
		-0.5f, -0.5f,
     	0.5f, -0.5f,
    	0.0f,  0.5f
	});

	Scout::Renderer::Shader shader(R"(
		#version 330 core
		layout (location = 0) in vec2 vertexPos;


		void main() {
			gl_Position = vec4(vertexPos, 0.0f, 1.0f);
		}

	)", R"(
			
		#version 330 core
		out vec4 fragmentColor;

		void main() {
			fragmentColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);
		}

	)");

	while (window.isOpen()) {
		window.pollEvents();
		window.clear(0.0f, 0.0f, 0.0f);
	
		shader.setCurrent();
		Scout::Renderer::drawVertexArray(vertexArray);
		window.present();

	}

	window.close();
	
	glfwTerminate();

	return 0;

}
