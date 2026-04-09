#pragma once
#include <window.hpp>
#include <gl33context.hpp>


namespace Scout {
	
	/**
	 * @brief Class that handles initialization of a graphics API.
	 *
	 * @details
	 * The `GraphicsContext` class is really just a class that holds a pointer to the real graphics context. This is so a different graphics API can be initialized without recompiling. 
	 *
	*/
	class GraphicsContext {

		private:
		void* handle = nullptr;

		public:
		GraphicsContext(Window* window);
		virtual ~GraphicsContext();

	};

}
