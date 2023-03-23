#include "pch.h"
#include "EngineApp.h"

#include "Window/Window.h"
#include "Logger/Logger.h"

using namespace MCEngine;

#include "EventSystem/Message.h"
#include "EventSystem/EventBus.h"
#include "EventSystem/Event.h"

class EventA : public Event
{
public:
    EventA(EventBus* eventBus) : Event(eventBus) {}

    void update()
    {
        Message greeting("Bye!");
        send(greeting);
    }

private:
    void onNotify(Message message)
    {
        std::cout << "A received: " << message.getEvent() << std::endl;
    }
};

// This class will send a message to ComponentA.
class EventB : public Event
{
public:
    EventB(EventBus* eventBus) : Event(eventBus) {}

    void update()
    {
        Message greeting("Hi!");
        send(greeting);
    }

private:
    void onNotify(Message message)
    {
        std::cout << "B received: " << message.getEvent() << std::endl;
    }
};


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
    EventA compA(&eventBus);
    EventB compB(&eventBus);

    // This is supposed to act like a game loop.
    for (int ctr = 0; ctr < 5; ctr++) {
        compA.update();
        compB.update();
        eventBus.notify();

        
    }

	while (!window->windowShouldClose()) {
        window->pollEvents();
	}

	return 0;
}
