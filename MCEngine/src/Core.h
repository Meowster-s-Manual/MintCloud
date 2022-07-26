#pragma once

#ifdef BUILD_DLL
	#define ENGINE_API __declspec(dllexport)
#else
	#define ENGINE_API __declspec(dllimport)
#endif

#define BIT(x) (1 << x)