#include "pch.h"
#include "EngineApp.h"

#include "EventSystem/Events/KeyboardEvent.h"
#include "EventSystem/Events/MouseEvent.h"

#include "Logger/Logger.h"
#include <GLFW/glfw3.h>

using namespace std;

namespace MCEngine {
	EngineApp::EngineApp()
	{
	}

	EngineApp::~EngineApp()
	{
	}

	int EngineApp::start()
	{
		string s;
		Logger::init();
		KeyboardPressEvent e(21, false);
		//std::cout << e.debugString() << std::endl;
		MINT_INFO(e.debugString());
		MINT_INFO(2323232);

		MouseButtonPressEvent et(0);
		cout << et.debugString() << endl;

		MouseScrollEvent etc(231, 323);
		cout << etc.debugString() << endl;

		GLFWwindow* wnd;
		glfwInit();
		wnd = glfwCreateWindow(800, 600, "Hello World!", nullptr, nullptr);
		glfwMakeContextCurrent(wnd);

		while (true) {
			OPTICK_FRAME("MCEngine");
			//cout << "Type yes to shutdown\n$ ";
			//cin >> s;
			//if (s == "yes")
			//	break;
			cout << ".";
			Sleep(500);
		}
		OPTICK_SHUTDOWN();

		return 0;
	}

}