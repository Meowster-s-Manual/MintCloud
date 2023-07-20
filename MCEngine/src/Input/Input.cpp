#include "pch.h"
#include "Input.h"

using namespace MCEngine;


KeyboardEvent::KeyboardEvent(Window*& window)
{
    this->window = window;
}

void KeyboardEvent::update()
{
    glfwSetKeyCallback(this->window->getWindow(), this->key_callback);
}

void KeyboardEvent::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    // TODO remove testing
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}