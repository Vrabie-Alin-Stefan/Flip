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

#ifdef HZ_ENABLE_ASSERTS
	#define FP_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define FP_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define FP_ASSERT(x, ...)
	#define FP_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)