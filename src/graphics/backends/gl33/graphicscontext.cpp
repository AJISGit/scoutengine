#include <graphicscontext.hpp>


Scout::GraphicsContext::GraphicsContext(Scout::Window* window) {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {
		handle = new Scout::GL33Context(window);
	}

}


Scout::GraphicsContext::~GraphicsContext() {

	if (Scout::renderer == Scout::RendererType::OpenGL33) {
		delete static_cast<Scout::GL33Context*>(handle);
	}
}

