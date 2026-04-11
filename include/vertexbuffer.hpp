#pragma once
#include <scout.hpp>
#include <vector>
#include <initializer_list>


namespace Scout::Renderer {
	/**
	 * Class to allocate memory for vertices on the GPU.
	*/
	class VertexBuffer {

		private:
		std::vector<float> vertices;
		unsigned int VBO;

		public:
		/**
		 * @param vertices The vertices to be stored in the buffer.
		*/
		VertexBuffer(std::initializer_list<float> vertices);
		virtual ~VertexBuffer();

		/**
		 * Gets the API specific handle to the vertex buffer.
		 * @return The handle to the vertex buffer.
		*/
		unsigned int getHandle() const;
		/**
		 * Gets the amount of vertices in the buffer.
		 * @details
		 * This actually returns the amount of vertices in the internal `std::vector`. But unless they get modified outside of the object's knowledge, they are both the same.
		*/
		unsigned int getAmount() const;

	};

}
