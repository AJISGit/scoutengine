#include <clear.hpp>


void Scout::Renderer::clearColor(float r, float g, float b) {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(r, g, b, 1.0f);
}
