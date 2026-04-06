#include <window.hpp>


Scout::Window::Window(std::string_view title, unsigned int width, unsigned int height) {

	this->title = title.data();
	this->width = width;
	this->height = height;

	#ifdef SCOUT_USE_GLFW
		
		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		handle = glfwCreateWindow(width, height, this->title.c_str(), nullptr, nullptr);

	#endif

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

