#pragma once

#include <scoutconfig.hpp>

#if defined(SCOUT_USE_GLFW)
	#include <glad/glad.h>
	#include <GLFW/glfw3.h>
#endif

namespace Scout {

	enum class PlatformType { Windows, MacOS, Linux, Unknown };
	enum class WindowType { GLFW, Unknown };
	enum class RendererType { OpenGL33, Unknown };

	extern PlatformType platform;
	extern WindowType windowType;
	extern RendererType renderer;
	
	#if defined(SCOUT_USE_GLFW)
		using WindowHandle = GLFWwindow*;
	#endif

}
