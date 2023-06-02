#include "pch.h"
#include "InputEvent.h"

using namespace MCEngine;

void InputEvent::update()
{
}

void InputEvent::onNotify(Message message)
{
}

void KeyboardEvent::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}
