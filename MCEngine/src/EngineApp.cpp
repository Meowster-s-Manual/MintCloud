#include "PCH.h"
#include "EngineApp.h"

#include "EventSystem/Events/KeyboardEvent.h"
#include "EventSystem/Events/MouseEvent.h"

using namespace MCEngine;

EngineApp::EngineApp()
{
}

EngineApp::~EngineApp()
{
}

int EngineApp::start()
{
	KeyboardPressEvent e(21, false);
	std::cout << e.debugString() << std::endl;

	MouseButtonPressEvent et(0);
	std::cout << et.debugString() << std::endl;

	MouseScrollEvent etc(231, 323);
	std::cout << etc.debugString() << std::endl;

	while (true) {}
	return 0;
}
