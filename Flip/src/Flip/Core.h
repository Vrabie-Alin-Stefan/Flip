#pragma once

#ifdef FP_PLATFORM_WINDOWS
	#ifdef FP_BUILD_DLL
		#define FLIP_API __declspec(dllexport)
	#else
		#define FLIP_API __declspec(dllimport)
	#endif
#else
	#error Flip support only Windows!
#endif

#define BIT(x) (1 << x)