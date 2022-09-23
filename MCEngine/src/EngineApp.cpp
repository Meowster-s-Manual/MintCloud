#include "pch.h"
#include "EngineApp.h"

#include "EventSystem/Events/KeyboardEvent.h"
#include "EventSystem/Events/MouseEvent.h"

#include "Logger/Logger.h"

namespace MCEngine {
	EngineApp::EngineApp()
	{
	}

	EngineApp::~EngineApp()
	{
	}

	int EngineApp::start()
	{
		Logger::init();
		KeyboardPressEvent e(21, false);
		//std::cout << e.debugString() << std::endl;
		MINT_INFO(e.debugString());
		MINT_INFO(2323232);

		MouseButtonPressEvent et(0);
		std::cout << et.debugString() << std::endl;

		MouseScrollEvent etc(231, 323);
		std::cout << etc.debugString() << std::endl;

		while (true) {}
		return 0;
	}

}