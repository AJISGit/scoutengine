#pragma once
#include <scout.hpp>
#include <vector>
#include <initializer_list>


// This is literally the VertexBuffer class copy and pasted.
// Is this bad code design? Yes. Am I going to change it? No.
// - Aj 2026


namespace Scout::Renderer {
	/**
	 * Class to allocate memory for indices on the GPU.
	*/
	class ElementBuffer {

		private:
		std::vector<unsigned int> indices;
		unsigned int EBO;

		public:
		/**
		 * @param indices The indices to be stored in the buffer.
		*/
		ElementBuffer(std::initializer_list<unsigned int> indices, bool initialize = false);
		virtual ~ElementBuffer();


		/**
		 * Initializes the actual resource.
		*/
		void init();


		/**
		 * Gets the API specific handle to the element buffer.
		 * @return The handle to the element buffer.
		*/
		unsigned int getHandle() const;
		/**
		 * Gets the amount of indices in the buffer.
		 * @details
		 * This actually returns the amount of indices in the internal `std::vector`. But unless they get modified outside of the object's knowledge, they are both the same.
		*/
		unsigned int getAmount() const;

	};

}
