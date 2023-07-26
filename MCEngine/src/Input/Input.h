#pragma once
#include "Macros.h"
#include "Window/Window.h"
#include "KeyboardCodes.h"

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
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
        bool keyPress(KeyCode key);
    private:
        Window* window;
    };

    class ENGINE_API MouseEvent : public Input
    {
    };
}