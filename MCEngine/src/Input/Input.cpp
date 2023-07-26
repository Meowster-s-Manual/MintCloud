#include "pch.h"
#include "Input.h"

using namespace MCEngine;


KeyboardEvent::KeyboardEvent(Window*& window)
{
    this->window = window;
}

void KeyboardEvent::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // TODO remove testing
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

bool KeyboardEvent::keyPress(KeyCode key)
{
    const int state = glfwGetKey(this->window->getWindow(), static_cast<int32_t>(key));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
    
}