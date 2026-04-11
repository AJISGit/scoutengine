#pragma once
#include <vertexarray.hpp>
#include <shader.hpp>


namespace Scout::Renderer {

	/**
	 * Draws a `VertexArray`.
	 * @details
	 * This is the equivilant of `glDrawArrays`. Except it automatically binds the `VertexArray`.
	 * @param vertexArray The `VertexArray` to be drawn.
	*/
	void drawVertexArray(const VertexArray& vertexArray);

}

