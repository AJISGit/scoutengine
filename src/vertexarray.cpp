#include <vertexarray.hpp>


Scout::Renderer::VertexArray::VertexArray(Scout::Renderer::VertexBuffer* vertexBuffer, std::vector<Scout::Renderer::VertexAttribute*>& vertexAttributes, bool initialize) : attribs(vertexAttributes) {

	this->vertexBuffer = vertexBuffer;

	if (initialize) init();

}


void Scout::Renderer::VertexArray::init() {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {

		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

	
		vertexBuffer->init();
		
		for (Scout::Renderer::VertexAttribute* attrib : attribs) {
			attrib->init();
		}

	}

}


Scout::Renderer::VertexArray::~VertexArray() {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {
		glDeleteVertexArrays(1, &VAO);
	}

}


unsigned int Scout::Renderer::VertexArray::getHandle() const {
	return VAO;
}


const Scout::Renderer::VertexBuffer* Scout::Renderer::VertexArray::getVertexBuffer() const {
	return vertexBuffer;
}


const std::vector<Scout::Renderer::VertexAttribute*>& Scout::Renderer::VertexArray::getVertexAttribs() const {
	return attribs;
}

