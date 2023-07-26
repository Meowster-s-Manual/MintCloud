#include "pch.h"
#include "EngineApp.h"
#include "Input/Input.h"

#include "Window/Window.h"
#include "Logger/Logger.h"

using namespace MCEngine;
using namespace Key;

EngineApp::EngineApp()
{
	Logger::init();
}

EngineApp::~EngineApp()
{

}

int EngineApp::start()
{
    MINT_INFO("Starting Game");

    Window* window = new Window();
    window->init("WHAT ARE YOU DOING ANDREW");

    KeyboardEvent* keyboardEvent = new KeyboardEvent(window);

    int counter = 0; 
	while (!window->windowShouldClose()) {
        window->pollEvents();
        if (keyboardEvent->keyPress(ESC))
        {
            glfwSetWindowShouldClose(window->getWindow(), GLFW_TRUE);
        }
	}

	return 0;
}