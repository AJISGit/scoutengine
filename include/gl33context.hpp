#pragma once
#include <window.hpp>


namespace Scout {
	
	/// Graphics context for OpenGL 3.3
	class GL33Context {

		private:
		Window* window = nullptr;
		WindowHandle platformWindow = {};

		public:
		GL33Context(Window* window);

	};

}
