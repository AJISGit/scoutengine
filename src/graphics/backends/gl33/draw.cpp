#include <draw.hpp>


void Scout::Renderer::drawVertexArray(const Scout::Renderer::VertexArray& vertexArray) {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {

		unsigned int VAO = vertexArray.getHandle();
		const std::vector<Scout::Renderer::VertexAttribute*>& attribs = vertexArray.getVertexAttribs();

		unsigned int size = 0;

		for (Scout::Renderer::VertexAttribute* attrib : attribs) {
			size += attrib->getSize();
		}

		unsigned int count = vertexArray.getVertexBuffer()->getAmount() / size;

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, count);
		glBindVertexArray(0);	

	}

}


void Scout::Renderer::drawElements(const Scout::Renderer::VertexArray& vertexArray) {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {

		unsigned int VAO = vertexArray.getHandle();

		unsigned int count = vertexArray.getElementBuffer()->getAmount();

		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
		glBindVertexArray(0);	

	}

}

