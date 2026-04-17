#pragma once
#include <vertexbuffer.hpp>
#include <elementbuffer.hpp>
#include <vertexattrib.hpp>
#include <vector>


namespace Scout::Renderer {

	/**
	 * Class to store a vertex array.
	 * @details
	 * Learn more about vertex arrays [here.](https://wikis.khronos.org/opengl/Vertex_Specification#Vertex_Array_Object)
	*/
	class VertexArray {
		
		private:
		VertexBuffer* vertexBuffer = nullptr;
		ElementBuffer* elementBuffer = nullptr;
		unsigned int VBO;
		unsigned int EBO;
		unsigned int VAO;

		std::vector<VertexAttribute*>& attribs;

		public:
		/**
		 * @param vertices The vertices to be stored in the internal `VertexBuffer`.
		*/
		VertexArray(VertexBuffer* vertexBuffer, ElementBuffer* elementBuffer, std::vector<VertexAttribute*>& vertexAttributes, bool initialize = true);
		virtual ~VertexArray();

		
		/**
		 * Initializes the actual resource.
		*/
		void init();

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
		const ElementBuffer* getElementBuffer() const;
		const std::vector<VertexAttribute*>& getVertexAttribs() const;

	};

}
