#include <scout.hpp>


#if defined (SCOUT_USE_GLFW)
	Scout::WindowType Scout::windowType = Scout::WindowType::GLFW;
#endif


#if defined(_WIN32)
	Scout::PlatformType Scout::platform = Scout::PlatformType::Windows;
#elif defined(__linux__)
	Scout::PlatformType Scout::platform = Scout::PlatformType::Linux;
#elif defined(__APPLE__)
	Scout::PlatformType Scout::platform = Scout::PlatformType::MacOS;
#else
	Scout::PlatformType Scout::platform = Scout::PlatformType::Unknown;
#endif

Scout::RendererType Scout::renderer = Scout::RendererType::OpenGL33;
