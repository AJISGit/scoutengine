#include <gl33context.hpp>

#if defined(SCOUT_USE_GLFW)

	void onWindowResize(GLFWwindow* window, int width, int height) {
		glViewport(0, 0, width, height);
	}

#endif

Scout::GL33Context::GL33Context(Scout::Window* window) {

	this->window = window;
	platformWindow = window->getWindowHandle();
	
	#if defined(SCOUT_USE_GLFW)

		glfwMakeContextCurrent(platformWindow);
		gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress));	
		
		glfwSetFramebufferSizeCallback(platformWindow, onWindowResize);

	#endif

}

