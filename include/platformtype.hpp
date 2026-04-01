#pragma once


namespace Scout {

	enum class PlatformType { Windows, MacOS, Linux, Unknown };
	enum class WindowType { GLFW, Unknown };

	extern PlatformType platform;
	extern WindowType windowType;

}
