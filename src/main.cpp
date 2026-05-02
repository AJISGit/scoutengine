#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <scout.hpp>
#include <window.hpp>
#include <draw.hpp>
#include <texture.hpp>
#include <stb_image.h>
#include <iostream>


int main() {

	glfwInit();
	
	Scout::Window window("Test Window", 800, 600);
	
	
	stbi_set_flip_vertically_on_load(true);
	int width, height, channels;
	unsigned char* data = stbi_load("./img.png", &width, &height, &channels, 0);
	Scout::Texture texture(data, width, height, Scout::TextureWrapMethod::Repeat, Scout::TextureWrapMethod::Repeat, Scout::TextureMinFilter::Nearest, Scout::TextureMagFilter::Nearest, Scout::TextureFormat::RGBA);

	if (!data) {
		std::cerr << "Failed to load texture.\n";
	}

	stbi_image_free(data);


	Scout::Renderer::VertexBuffer vertexBuffer({
		// Position		UV 
		-0.5f, -0.5f, 	0.0f, 0.0f, // Bottom Left
     	0.5f, -0.5f,	1.0f, 0.0f, // Bottom Right
    	-0.5f,  0.5f,  	0.0f, 1.0f, // Top Left
		0.5f, 0.5f,		1.0f, 1.0f // Top Right
	});

	Scout::Renderer::ElementBuffer elementBuffer({
		0, 1, 3,
		3, 2, 0 
	});

	Scout::Renderer::VertexAttribute attrib0(0, 2, false, 4 * sizeof(float), 0);
	Scout::Renderer::VertexAttribute attrib1(1, 2, false, 4 * sizeof(float), 2 * sizeof(float));
	std::vector<Scout::Renderer::VertexAttribute*> vertexAttribs = { &attrib0, &attrib1 };


	Scout::Renderer::VertexArray vertexArray(&vertexBuffer, &elementBuffer, vertexAttribs);

	Scout::Renderer::Shader shader(R"(
		#version 330 core
		layout (location = 0) in vec2 aPos;
		layout (location = 1) in vec2 aUV;
		out vec2 uvCoord;


		void main() {
			gl_Position = vec4(aPos, 0.0f, 1.0f);
			uvCoord = aUV;
		}

	)", R"(
			
		#version 330 core
		in vec2 uvCoord;
		out vec4 fragmentColor;

		uniform sampler2D image;

		void main() {
			fragmentColor = texture(image, uvCoord);
		}

	)");

	unsigned int texID = texture.getId();
	unsigned int shaderID = shader.getHandle();

	while (window.isOpen()) {
		window.pollEvents();
		window.clear(0.2f, 0.2f, 0.2f);
	
		shader.setCurrent();

		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texID);

		shader.setUniform("image", 0);
		
		Scout::Renderer::drawElements(vertexArray);
		window.present();

	}

	window.close();
	
	glfwTerminate();

	return 0;

}
