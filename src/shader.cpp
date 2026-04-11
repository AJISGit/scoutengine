#include <shader.hpp>
#include <iostream>


Scout::Renderer::Shader::Shader(std::string_view vertexShaderSrc, std::string_view fragmentShaderSrc) {

	this->vertexShaderSrc = vertexShaderSrc;
	this->fragmentShaderSrc = fragmentShaderSrc;

	if (Scout::renderer == Scout::RendererType::OpenGL33) {

		const char* vertexShaderSrcPtr = this->vertexShaderSrc.c_str();

		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSrcPtr, nullptr);
		glCompileShader(vertexShader);

		int success;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
		char infoLog[512];
		if (!success) {
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);	
			std::cerr << "Error compiling vertex shader: " << infoLog << '\n';
		}


		const char* fragmentShaderSrcPtr = this->fragmentShaderSrc.c_str();

		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSrcPtr, nullptr);
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
			std::cout << "Error compiling fragment shader: " << infoLog << '\n';
		}


		shader = glCreateProgram();
		glAttachShader(shader, vertexShader);
		glAttachShader(shader, fragmentShader);
		glLinkProgram(shader);


		glGetProgramiv(shader, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shader, 512, nullptr, infoLog);
			std::cout << "Error compiling fragment shader: " << infoLog << '\n';
		}


		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);


	}

}


Scout::Renderer::Shader::~Shader() {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {
		glDeleteProgram(shader);
	}

}


void Scout::Renderer::Shader::setCurrent() {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {
		glUseProgram(shader);
	}

}


unsigned int Scout::Renderer::Shader::getHandle() const {
	return shader;
}

