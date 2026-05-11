#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <scout.hpp>
#include <window.hpp>
#include <draw.hpp>
#include <texture.hpp>
#include <stb_image.h>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


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
		0.0f, 128.0f, 	0.0f, 0.0f, // Bottom Left
     	128.0f, 128.0f,	1.0f, 0.0f, // Bottom Right
    	0.0f,  0.0f,  	0.0f, 1.0f, // Top Left
		128.0f, 0.0f,		1.0f, 1.0f // Top Right
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

		uniform mat4 model;
		uniform mat4 projection;


		void main() {
			gl_Position = projection * model * vec4(aPos, 0.0f, 1.0f);
			gl_Position.z = 0.1f;
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


	glm::vec2 position = { 0.0f, 0.0f };
	float speed = 300.0f;

	float deltaTime = 0.0f;
	float lastFrame = 0.0f;

	while (window.isOpen()) {

		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		window.pollEvents();
		window.clear(0.2f, 0.2f, 0.2f);
	
		shader.setCurrent();

		texture.enable(0);
		shader.setUniform("image", 0);


		glm::mat4 model(1.0f);
		
		if (window.isKeyDown(Scout::Input::Key::W)) {
			position.y -= speed * deltaTime;
		}
		if (window.isKeyDown(Scout::Input::Key::A)) {
			position.x -= speed * deltaTime;
		}
		if (window.isKeyDown(Scout::Input::Key::S)) {
			position.y += speed * deltaTime;
		}
		if (window.isKeyDown(Scout::Input::Key::D)) {
			position.x += speed * deltaTime;
		}

		model = glm::translate(model, glm::vec3(position, 0.0f));

		glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(window.getWidth()), static_cast<float>(window.getHeight()), 0.0f, 0.1f, 10.0f);

		shader.setUniform("model", model);
		shader.setUniform("projection", projection);

		Scout::Renderer::drawElements(vertexArray);
		window.present();

	}


	texture.destroy();
	vertexArray.destroy();
	vertexBuffer.destroy();
	elementBuffer.destroy();
	shader.destroy();


	window.close();
	
	glfwTerminate();

	return 0;

}
