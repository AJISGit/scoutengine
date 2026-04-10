#pragma once
#include <scout.hpp>
#include <string_view>



namespace Scout {
	
	class GraphicsContext;

	class Window {

		private:

		WindowHandle handle = {};
		unsigned int width = 0;
		unsigned int height = 0;
		std::string title;
		GraphicsContext* graphicsContext = nullptr;

		// Open is if the window still open, while closed is if close() has been called.
		bool open = true;
		bool closed = false;

		public:
		
		/**
		 * @param title The title of the window.
		 * @param width The width of the window in pixels.
		 * @param height The height of the window in pixels.
		*/
		Window(std::string_view title, unsigned int width, unsigned int height);
		virtual ~Window();


		/// Gets the title of the window.
		std::string getTitle();
		/// Sets the title of the window.
		void setTitle(std::string_view title);
		
		/// Gets the width of the window.
		unsigned int getWidth();
		/// Sets the width of the window.
		void setWidth(unsigned int width);

		/// Gets the height of the window.
		unsigned int getHeight();
		/// Sets the height of the window.
		void setHeight(unsigned int height);

		/// Checks if the window is still open.
		bool isOpen();

		/// Gets the OS specific window handle.
		WindowHandle getWindowHandle();
		
		/// Closes the window. This is called automatically by the destructor.
		void close();

		/**
		 * @brief Polls window events (closing, moving, etc.)
		 *
		 * @detail
		 * This function really polls events for all windows open.
		*/
		void pollEvents();



	};

}
