#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <scout.hpp>
#include <window.hpp>
#include <draw.hpp>


int main() {

	glfwInit();
	
	Scout::Window window("Test Window", 800, 600);
	
	

	Scout::Renderer::VertexBuffer vertexBuffer({
		// Position		Color 
		-0.5f, -0.5f, 	1.0f, 0.0f, 0.0f, // Bottom Left
     	0.5f, -0.5f,	0.0f, 1.0f, 0.0f, // Bottom Right
    	-0.5f,  0.5f,  	0.0f, 0.0f, 1.0f, // Top Left
		0.5f, 0.5f,		1.0f, 1.0f, 0.0f // Top Right
	});

	Scout::Renderer::ElementBuffer elementBuffer({
		0, 1, 3,
		3, 2, 0 
	});

	Scout::Renderer::VertexAttribute attrib0(0, 2, false, 5 * sizeof(float), 0);
	Scout::Renderer::VertexAttribute attrib1(1, 3, false, 5 * sizeof(float), 2 * sizeof(float));
	std::vector<Scout::Renderer::VertexAttribute*> vertexAttribs = { &attrib0, &attrib1 };


	Scout::Renderer::VertexArray vertexArray(&vertexBuffer, &elementBuffer, vertexAttribs);

	Scout::Renderer::Shader shader(R"(
		#version 330 core
		layout (location = 0) in vec2 aPos;
		layout (location = 1) in vec3 aColor;
		out vec3 vertexColor;


		void main() {
			gl_Position = vec4(aPos, 0.0f, 1.0f);
			vertexColor = aColor;
		}

	)", R"(
			
		#version 330 core
		in vec3 vertexColor;
		out vec4 fragmentColor;

		void main() {
			fragmentColor = vec4(vertexColor, 1.0f);
		}

	)");

	while (window.isOpen()) {
		window.pollEvents();
		window.clear(0.0f, 0.0f, 0.0f);
	
		shader.setCurrent();
		Scout::Renderer::drawElements(vertexArray);
		window.present();

	}

	window.close();
	
	glfwTerminate();

	return 0;

}
