#include "pch.h"
#include "EngineApp.h"

#include "Window/Window.h"
#include "Logger/Logger.h"

namespace MCEngine {
	EngineApp::EngineApp()
	{
		Logger::init();
	}

	EngineApp::~EngineApp()
	{
		OPTICK_SHUTDOWN();
	}

	int EngineApp::start()
	{
		MINT_INFO("Starting Game");

		Window* window = new Window();
		window->init("WHAT ARE YOU DOING ANDREW");

		while (!window->windowShouldClose()) {
			OPTICK_FRAME("MCEngine");
			window->pollEvents();
			//Sleep(500); // for debugging with optick
		}

		return 0;
	}

}