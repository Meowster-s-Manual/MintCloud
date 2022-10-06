#pragma once
#ifdef WIN_OS
	#ifdef BUILD_DLL
		#define ENGINE_API __declspec(dllexport)
	#else
		#define ENGINE_API __declspec(dllimport)
	#endif
#endif

#define BIT(x) (1 << x)