#include "pch.h"
#include "EngineApp.h"

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

	while (!window->windowShouldClose()) {

		window->pollEvents();

	}

	return 0;
}
