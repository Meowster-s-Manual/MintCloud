#pragma once
#include "Macros.h"

namespace MCEngine {
	class ENGINE_API SysWindow
	{
	public:
		SysWindow();
		~SysWindow();

		GLFWwindow* createWindow(int width, int height, const char* title);
	private:
		uint32_t extensionCount = 0;
	};
}