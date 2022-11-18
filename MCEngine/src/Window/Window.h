#pragma once
#include "Macros.h"

#ifdef WIN_OS
	#include "Windows/window.h"
#elif LNX_OS
	#include "Linux/window.h"
#endif

namespace MCEngine {
	class ENGINE_API AppWindow
	{
	public:
		AppWindow();
		~AppWindow();

		int Init();
	private:
	};
}