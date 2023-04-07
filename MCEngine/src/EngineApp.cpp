#include "pch.h"
#include "EngineApp.h"

#include "Window/Window.h"
#include "Logger/Logger.h"

using namespace MCEngine;

#include "EventSystem/Message.h"
#include "EventSystem/EventBus.h"
#include "EventSystem/Event.h"

class ENGINE_API InputEvent : public Event
{
public:
    InputEvent(EventBus* eventBus) : Event(eventBus) {}
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

class ENGINE_API KeyboardEvent : public InputEvent
{
public:
    KeyboardEvent(EventBus* eventBus) : InputEvent(eventBus) {}
    static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
            glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
private:
};

class ENGINE_API MouseEvent : public InputEvent 
{
    //TODO: Discuss if we want 2 filters here or seperate into two classes
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
    KeyboardEvent keebs(&eventBus);
    EventB compB(&eventBus);


    // This is supposed to act like a game loop.
    for (int ctr = 0; ctr < 5; ctr++) {
        keebs.update();
        compB.update();
        eventBus.notify();

        
    }

	while (!window->windowShouldClose()) {
        window->pollEvents();
        glfwSetKeyCallback(window->window, keebs.key_callback);
	}

	return 0;
}