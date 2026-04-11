#pragma once
#include <scout.hpp>


namespace Scout::Renderer {

	/**
	 * A class for managing the creation and compilation of shaders.
	*/
	class Shader {

		private:
		std::string vertexShaderSrc;
		std::string fragmentShaderSrc;

		unsigned int vertexShader;
		unsigned int fragmentShader;
		unsigned int shader;

		public:
		/**
		 * Constructor for the `Shader` class.
		 * @details
		 * This will output error messages to `std::cerr` if there are any errors compiling or linking the shaders.
		 * @param vertexShaderSrc The source code for the vertex shader.
		 * @param fragmentShaderSrc The source code for the fragment shader.
		*/
		Shader(std::string_view vertexShaderSrc, std::string_view fragmentShaderSrc);
		virtual ~Shader();

		/**
		 * Sets this shader as the current shader.
		*/
		void setCurrent();
		/**
		 * Returns the API specific handle to the shader program.
		 * @return The handle to the shader program.
		*/
		unsigned int getHandle() const;

	};

}
