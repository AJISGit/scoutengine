#include <elementbuffer.hpp>
// I hate this, but I'm too lazy to use good programming practices.


Scout::Renderer::ElementBuffer::ElementBuffer(std::initializer_list<unsigned int> indices, bool initialize) {
	
	this->indices = indices;
	if (initialize) init();

}


void Scout::Renderer::ElementBuffer::init() {

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indices.size() * sizeof(float), this->indices.data(), GL_STATIC_DRAW);

}


Scout::Renderer::ElementBuffer::~ElementBuffer() {
	destroy();
}


void Scout::Renderer::ElementBuffer::destroy() {
	if (destroyed) return;
	destroyed = true;
	glDeleteBuffers(1, &EBO);
}


unsigned int Scout::Renderer::ElementBuffer::getHandle() const {
	return EBO;
}


unsigned int Scout::Renderer::ElementBuffer::getAmount() const {
	return indices.size();
}

