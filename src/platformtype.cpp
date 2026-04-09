#include <scout.hpp>


#if defined (SCOUT_USE_GLFW)
	Scout::WindowType Scout::windowType = Scout::WindowType::GLFW;
#endif



#if defined(_WIN32)
	Scout::PlatformType Scout::platform = Scout::PlatformType::Windows;
#else
	#error Only Windows is supported.
#endif

Scout::RendererType Scout::renderer = Scout::RendererType::OpenGL33;
