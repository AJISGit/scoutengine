#include <scout.hpp>


#if !defined (SCOUT_USE_NATIVE_APIS)
	Scout::WindowType Scout::windowType = Scout::WindowType::GLFW;
#else
	#error Native window APIs are not supported.
#endif



#if defined(_WIN32)
	Scout::PlatformType Scout::platform = Scout::PlatformType::Windows;
#else
	#error Only Windows is supported.
#endif
