#pragma once
#include "../Message.h"
#include "../EventBus.h"
#include "../Event.h"

namespace MCEngine {
    class ENGINE_API InputEvent : public Event
    {
    public:
        InputEvent(EventBus* eventBus) : Event(eventBus) {}

        void update();

    private:
        void onNotify(Message message);
    };

    class ENGINE_API KeyboardEvent : public InputEvent
    {
    public:
        KeyboardEvent(EventBus* eventBus) : InputEvent(eventBus) {}

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    private:
    };

    class ENGINE_API MouseEvent : public InputEvent
    {
        MouseEvent(EventBus* eventBus) : InputEvent(eventBus) {}
        //TODO: Discuss if we want 2 filters here or seperate into two classes
    };
}