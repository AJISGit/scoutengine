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
	int tempWidth;
	int tempHeight;
	glfwGetWindowSize(getWindowHandle(), &tempWidth, &tempHeight);
	width = tempWidth;
	height = tempHeight;
	return width;
}


void Scout::Window::setWidth(unsigned int width) {
	this->width = width;
}


unsigned int Scout::Window::getHeight() {
	int tempWidth;
	int tempHeight;
	glfwGetWindowSize(getWindowHandle(), &tempWidth, &tempHeight);
	width = tempWidth;
	height = tempHeight;
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


bool Scout::Window::isKeyDown(Scout::Input::Key key) {

	GLFWwindow* window = getWindowHandle();
	
	switch (key) {

		case Scout::Input::Key::A:
			return glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS;
		case Scout::Input::Key::B:
			return glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS;
		case Scout::Input::Key::C:
			return glfwGetKey(window, GLFW_KEY_C) == GLFW_PRESS;
		case Scout::Input::Key::D:
			return glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS;
		case Scout::Input::Key::E:
			return glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS;
		case Scout::Input::Key::F:
			return glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS;
		case Scout::Input::Key::G:
			return glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS;
		case Scout::Input::Key::H:
			return glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS;
		case Scout::Input::Key::I:
			return glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS;
		case Scout::Input::Key::J:
			return glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS;
		case Scout::Input::Key::K:
			return glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS;
		case Scout::Input::Key::L:
			return glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS;
		case Scout::Input::Key::M:
			return glfwGetKey(window, GLFW_KEY_M) == GLFW_PRESS;
		case Scout::Input::Key::N:
			return glfwGetKey(window, GLFW_KEY_N) == GLFW_PRESS;
		case Scout::Input::Key::O:
			return glfwGetKey(window, GLFW_KEY_O) == GLFW_PRESS;
		case Scout::Input::Key::P:
			return glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS;
		case Scout::Input::Key::Q:
			return glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS;
		case Scout::Input::Key::R:
			return glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS;
		case Scout::Input::Key::S:
			return glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS;
		case Scout::Input::Key::T:
			return glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS;
		case Scout::Input::Key::U:
			return glfwGetKey(window, GLFW_KEY_U) == GLFW_PRESS;
		case Scout::Input::Key::V:
			return glfwGetKey(window, GLFW_KEY_V) == GLFW_PRESS;
		case Scout::Input::Key::W:
			return glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS;
		case Scout::Input::Key::X:
			return glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS;
		case Scout::Input::Key::Y:
			return glfwGetKey(window, GLFW_KEY_Y) == GLFW_PRESS;
		case Scout::Input::Key::Z:
			return glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS;
	

	}

}

