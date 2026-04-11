#include <draw.hpp>

void Scout::Renderer::drawVertexArray(const Scout::Renderer::VertexArray& vertexArray) {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {

		unsigned int VAO = vertexArray.getHandle();
		glBindVertexArray(VAO);
		unsigned int count = vertexArray.getVertexBuffer()->getAmount();

		glDrawArrays(GL_TRIANGLES, 0, count);

		glBindVertexArray(0);	

	}

}
