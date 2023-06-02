#include "pch.h"
#include "EngineApp.h"
#include "EventSystem/CoreEvents/InputEvent.h"
#include "EventSystem/EventTemplate/EventTemplate.h"

#include "Window/Window.h"
#include "Logger/Logger.h"

using namespace MCEngine;

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

    EventBus eventBus;
    KeyboardEvent keyboardEvent(&eventBus);
    EventTemplate compB(&eventBus);

    int counter = 0; 
	while (!window->windowShouldClose()) {
        // Note: going to remove update to use EventBus::updateAll()
        keyboardEvent.update();
        compB.update();
        eventBus.notify();

        window->pollEvents();
        glfwSetKeyCallback(window->window, keyboardEvent.key_callback);
	}

	return 0;
}