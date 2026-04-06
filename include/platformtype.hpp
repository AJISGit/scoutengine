#pragma once
#include <GLFW/glfw3.h>
#include <scoutconfig.hpp>

namespace Scout {

	enum class PlatformType { Windows, MacOS, Linux, Unknown };
	enum class WindowType { GLFW, Unknown };

	extern PlatformType platform;
	extern WindowType windowType;
	
	#if defined(SCOUT_USE_GLFW)
	using WindowHandle = GLFWwindow*;
	#endif

}
