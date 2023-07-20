#pragma once
#include "Macros.h"
#include "Window/Window.h"

namespace MCEngine {
    class ENGINE_API Input
    {
    public:
        Input() {}
        void virtual update() {}

    private:
    };

    class ENGINE_API KeyboardEvent : public Input
    {
    public:
        KeyboardEvent(Window*& window);
        void update();
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
    private:
        Window* window;
    };

    class ENGINE_API MouseEvent : public Input
    {
    };
}