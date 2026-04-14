#pragma once
#include <scout.hpp>
#include <cstdint>


namespace Scout::Renderer {

	class VertexAttribute {
		
		private:
		unsigned int index;
		unsigned int size;
		bool normalized;
		std::size_t stride;
		std::intptr_t offset;



		public:
		VertexAttribute(unsigned int index, unsigned int size, bool normalized, std::size_t stride, std::intptr_t offset, bool initialize = false);

		/**
		 * Initializes the actual resource.
		*/
		void init();

		unsigned int getIndex() const;
		unsigned int getSize() const;
		bool isNormalized() const;
		std::size_t getStride() const;
		std::intptr_t getOffset() const;

	};

}
