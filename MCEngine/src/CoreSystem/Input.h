#pragma once
//TODO: Replace EventBus with base class for core systems (ex: Type)
namespace MCEngine {
    class ENGINE_API Input
    {
    public:
        Input(EventBus* eventBus) : Event(eventBus) {}
        void update();

    private:
        void onNotify(Message message);
    };

    class ENGINE_API KeyboardEvent : public Input
    {
    public:
        KeyboardEvent(EventBus* eventBus) : Input(eventBus) {}

        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    private:
    };

    class ENGINE_API MouseEvent : public Input
    {
        MouseEvent(EventBus* eventBus) : Input(eventBus) {}
        //TODO: Discuss if we want 2 filters here or seperate into two classes
    };
}