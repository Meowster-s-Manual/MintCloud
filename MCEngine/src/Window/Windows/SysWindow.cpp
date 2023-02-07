#include "pch.h"
#include "SysWindow.h"

#include "Logger/Logger.h"

using namespace MCEngine;

SysWindow::SysWindow()
{
	glfwInit();
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

SysWindow::~SysWindow()
{
	glfwTerminate();
}

GLFWwindow* SysWindow::createWindow(int width, int height, const char* title)
{
	GLFWwindow* window = glfwCreateWindow(width, height, title, nullptr, nullptr);

	vkEnumerateInstanceExtensionProperties(nullptr, &this->extensionCount, nullptr);
	MINT_INFO(std::to_string(this->extensionCount) + " extensions supported\n");

	return window;
}

