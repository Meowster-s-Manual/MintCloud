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
		//string s;
		//Logger::init();
		//KeyboardPressEvent e(21, false);
		////std::cout << e.debugString() << std::endl;
		//MINT_INFO(e.debugString());
		//MINT_INFO(2323232);

		//MouseButtonPressEvent et(0);
		//cout << et.debugString() << endl;

		//MouseScrollEvent etc(231, 323);
		//cout << etc.debugString() << endl;

		//GLFWwindow* wnd;
		//glfwInit();
		//wnd = glfwCreateWindow(800, 600, "Hello World!", nullptr, nullptr);
		//glfwMakeContextCurrent(wnd);

		//glm::mat4 matrix;
		//glm::vec4 vec;
		//auto test = matrix * vec;

		//while (true) {
		//	OPTICK_FRAME("MCEngine");
		//	//cout << "Type yes to shutdown\n$ ";
		//	//cin >> s;
		//	//if (s == "yes")
		//	//	break;
		//	cout << ".";
		//	//Sleep(500);
		//}
		//OPTICK_SHUTDOWN();
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		GLFWwindow* window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);

		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

		std::cout << extensionCount << " extensions supported\n";

		glm::mat4 matrix;
		glm::vec4 vec;
		auto test = matrix * vec;

		while (!glfwWindowShouldClose(window)) {
			glfwPollEvents();
		}

		glfwDestroyWindow(window);

		glfwTerminate();

		return 0;
	}

}