#pragma once
#include "Macros.h"

#ifdef WIN_OS
	#include "Windows/SysWindow.h"
#elif LNX_OS
	#include "Linux/SysWindow.h"
#endif

namespace MCEngine {
	class ENGINE_API Window
	{
	public:
		Window();
		~Window();

		int init(std::string windowName);
		int windowShouldClose();
		void pollEvents();
		GLFWwindow* getWindow();

		SysWindow* sysWindow;
		GLFWwindow* window;

		int windowWidth;
		int windowHeight;
	private:
	};
}