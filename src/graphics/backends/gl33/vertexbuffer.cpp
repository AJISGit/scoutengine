#include <vertexbuffer.hpp>


Scout::Renderer::VertexBuffer::VertexBuffer(std::initializer_list<float> vertices, bool initialize) {
	
	this->vertices = vertices;
	if (initialize) init();

}


void Scout::Renderer::VertexBuffer::init() {

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, this->vertices.size() * sizeof(float), this->vertices.data(), GL_STATIC_DRAW); 

}


Scout::Renderer::VertexBuffer::~VertexBuffer() {
	destroy();
}


void Scout::Renderer::VertexBuffer::destroy() {
	if (destroyed) return;
	destroyed = true;
	glDeleteBuffers(1, &VBO);
}


unsigned int Scout::Renderer::VertexBuffer::getHandle() const {
	return VBO;
}


unsigned int Scout::Renderer::VertexBuffer::getAmount() const {
	return vertices.size();
}

