#include <vertexarray.hpp>


Scout::Renderer::VertexArray::VertexArray(Scout::Renderer::VertexBuffer* vertexBuffer, Scout::Renderer::ElementBuffer* elementBuffer, std::vector<Scout::Renderer::VertexAttribute*>& vertexAttributes, bool initialize) : attribs(vertexAttributes) {

	this->vertexBuffer = vertexBuffer;
	this->elementBuffer = elementBuffer;

	if (initialize) init();

}


void Scout::Renderer::VertexArray::init() {

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	
	vertexBuffer->init();
	if (elementBuffer) elementBuffer->init();
		
	for (Scout::Renderer::VertexAttribute* attrib : attribs) {
		attrib->init();
	}


}


Scout::Renderer::VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &VAO);
}


unsigned int Scout::Renderer::VertexArray::getHandle() const {
	return VAO;
}


const Scout::Renderer::VertexBuffer* Scout::Renderer::VertexArray::getVertexBuffer() const {
	return vertexBuffer;
}


const Scout::Renderer::ElementBuffer* Scout::Renderer::VertexArray::getElementBuffer() const {
	return elementBuffer;
}


const std::vector<Scout::Renderer::VertexAttribute*>& Scout::Renderer::VertexArray::getVertexAttribs() const {
	return attribs;
}

