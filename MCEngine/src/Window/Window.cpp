#include "pch.h"
#include "Window.h"

using namespace MCEngine;
Window::Window()
{
	this->sysWindow = new SysWindow();
}

Window::~Window()
{
	glfwDestroyWindow(this->window);
}

int Window::init(std::string windowName)
{
	this->window = this->sysWindow->createWindow(1920, 1080, windowName.c_str());

	return 0;
}

int Window::windowShouldClose()
{
	OPTICK_EVENT();
	return glfwWindowShouldClose(this->window);
}

void Window::pollEvents()
{
	OPTICK_EVENT();
	glfwPollEvents();
}
