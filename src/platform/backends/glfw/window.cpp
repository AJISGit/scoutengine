#include <window.hpp>
#include <graphicscontext.hpp>
#include <clear.hpp>


Scout::Window::Window(std::string_view title, unsigned int width, unsigned int height) {

	this->title = title.data();
	this->width = width;
	this->height = height;
	
	// While I would prefer the context creation to be in a GraphicsContext class, GLFW does not support creating a context after window creation.
	// I could make a system for the GraphicsContext to tell the window to use some flags, that sounds compilated.

	#ifdef SCOUT_USE_GL33

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#else
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	#endif
	
	handle = glfwCreateWindow(width, height, this->title.c_str(), nullptr, nullptr);

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

	open = !glfwWindowShouldClose(handle);

	return open;

}


Scout::WindowHandle Scout::Window::getWindowHandle() {
	return handle;
}


void Scout::Window::close() {

	if (closed) return;

	delete graphicsContext;

	glfwDestroyWindow(handle);

	closed = true;

}


void Scout::Window::pollEvents() {

	glfwPollEvents();

}


void Scout::Window::clear(float r, float g, float b) {
	
	Scout::Renderer::clearColor(r, g, b);

}


void Scout::Window::present() {

	glfwSwapBuffers(getWindowHandle());

}
