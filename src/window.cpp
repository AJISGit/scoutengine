#include <window.hpp>
#include <graphicscontext.hpp>


Scout::Window::Window(std::string_view title, unsigned int width, unsigned int height) {

	this->title = title.data();
	this->width = width;
	this->height = height;

	#ifdef SCOUT_USE_GLFW
	
		// While I would prefer the context creation to be in a GraphicsContext class, GLFW does not support creating a context after window creation.
		// I could make a system for the GraphicsContext to tell the window to use some flags, that sounds compilated.

		if (Scout::renderer == Scout::RendererType::OpenGL33) {
			
			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		} else {
			glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		}
		handle = glfwCreateWindow(width, height, this->title.c_str(), nullptr, nullptr);

	#endif

	graphicsContext = new Scout::GraphicsContext(this);

}


Scout::Window::~Window() {
	close();
}


std::string Scout::Window::getTitle() {
	return title;
}


void Scout::Window::setTitle(std::string_view title) {
	this->title = title;
}


unsigned int Scout::Window::getWidth() {
	return width;
}


void Scout::Window::setWidth(unsigned int width) {
	this->width = width;
}


unsigned int Scout::Window::getHeight() {
	return height;
}


void Scout::Window::setHeight(unsigned int height) {
	this->height = height;
}


bool Scout::Window::isOpen() {

	#if defined(SCOUT_USE_GLFW)
	open = !glfwWindowShouldClose(handle);
	#endif

	return open;

}


Scout::WindowHandle Scout::Window::getWindowHandle() {
	return handle;
}


void Scout::Window::close() {

	if (closed) return;

	delete graphicsContext;

	#if defined (SCOUT_USE_GLFW)
		glfwDestroyWindow(handle);
	#endif

	closed = true;

}


void Scout::Window::pollEvents() {

	#if defined(SCOUT_USE_GLFW)
		glfwPollEvents();
	#endif

}


void Scout::Window::clear(float r, float g, float b) {
	
	if (Scout::renderer == Scout::RendererType::OpenGL33) {
		glClearColor(r, g, b, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}

}


void Scout::Window::present() {

	if ((Scout::windowType == Scout::WindowType::GLFW) && Scout::renderer == Scout::RendererType::OpenGL33) {
		glfwSwapBuffers(getWindowHandle());
	}

}
