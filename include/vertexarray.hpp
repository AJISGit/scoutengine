#pragma once
#include <vertexbuffer.hpp>


namespace Scout::Renderer {

	/**
	 * Class to store a vertex array.
	 * @details
	 * Learn more about vertex arrays [here.](https://wikis.khronos.org/opengl/Vertex_Specification#Vertex_Array_Object)
	*/
	class VertexArray {
		
		private:
		VertexBuffer* vertexBuffer = nullptr;
		unsigned int VBO;
		unsigned int VAO;

		public:
		/**
		 * @param vertices The vertices to be stored in the internal `VertexBuffer`.
		*/
		VertexArray(std::initializer_list<float> vertices);
		virtual ~VertexArray();

		/**
		 * Returns the API specific handle to the vertex array.
		 * @return The handle to the vertex array.
		*/ 
		unsigned int getHandle() const;	
		/**
		 * Returns a pointer to the internal `VertexBuffer`.
		 * @return A pointer to the internal `VertexBuffer`.
		*/
		const VertexBuffer* getVertexBuffer() const;

	};

}
