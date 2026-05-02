#include <vertexattrib.hpp>


Scout::Renderer::VertexAttribute::VertexAttribute(unsigned int index, unsigned int size, bool normalized, std::size_t stride, std::intptr_t offset, bool initialize) {

	this->index = index;
	this->size = size;
	this->normalized = normalized;
	this->stride = stride;
	this->offset = offset;

	if (initialize) init();

}


void Scout::Renderer::VertexAttribute::init() {

	glVertexAttribPointer(index, size, GL_FLOAT, normalized, stride, reinterpret_cast<void*>(offset));
	glEnableVertexAttribArray(index);

}


unsigned int Scout::Renderer::VertexAttribute::getIndex() const {
	return index;
}


unsigned int Scout::Renderer::VertexAttribute::getSize() const {
	return size;
}


bool Scout::Renderer::VertexAttribute::isNormalized() const {
	return normalized;
}


std::size_t Scout::Renderer::VertexAttribute::getStride() const {
	return stride;
}


std::intptr_t Scout::Renderer::VertexAttribute::getOffset() const {
	return offset;
}

