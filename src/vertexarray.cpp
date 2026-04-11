#include <vertexarray.hpp>


Scout::Renderer::VertexArray::VertexArray(std::initializer_list<float> vertices) {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		vertexBuffer = new Scout::Renderer::VertexBuffer(vertices);

		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), reinterpret_cast<void*>(0));
		glEnableVertexAttribArray(0);


	}

}


Scout::Renderer::VertexArray::~VertexArray() {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {
		glDeleteVertexArrays(1, &VAO);
		delete vertexBuffer;
	}

}


unsigned int Scout::Renderer::VertexArray::getHandle() const {
	return VAO;
}


const Scout::Renderer::VertexBuffer* Scout::Renderer::VertexArray::getVertexBuffer() const {
	return vertexBuffer;
}

