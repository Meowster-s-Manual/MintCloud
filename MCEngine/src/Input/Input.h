#pragma once
#include "Macros.h"
#include "Window/Window.h"
#include "KeyboardCodes.h"
#include "MouseCodes.h"

namespace MCEngine {
    class ENGINE_API Input
    {
    public:
        Input() {}

    protected:
        Window* window;
    private:
    };

    class ENGINE_API KeyboardEvent : public Input
    {
    public:
        KeyboardEvent(Window* window);
        void update();
        bool keyPress(KeyCode key);
    private:
    };

    class ENGINE_API MouseEvent : public Input
    {
    public:
        MouseEvent(Window* window);
        void update();
        bool mouseButtonPress(MouseCode button);
        void mousePosCallback(double* xpos, double* ypos);
    private:
    };
}