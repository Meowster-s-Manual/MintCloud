#include "pch.h"
#include "Input.h"

using namespace MCEngine;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

KeyboardEvent::KeyboardEvent(Window* window)
{
    this->window = window;
}

void KeyboardEvent::update()
{
    glfwSetKeyCallback(this->window->getWindow(), key_callback);
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    std::cout << key << std::endl;
}

bool KeyboardEvent::keyPress(KeyCode key)
{
    const int state = glfwGetKey(this->window->getWindow(), static_cast<int32_t>(key));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

MouseEvent::MouseEvent(Window* window)
{
    this->window = window;
}

void MouseEvent::update()
{
    glfwSetMouseButtonCallback(this->window->getWindow(), mouse_button_callback);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    std::cout << button << std::endl;
}

bool MouseEvent::mouseButtonPress(MouseCode button)
{
    const int state = glfwGetMouseButton(this->window->getWindow(), static_cast<int32_t>(button));
    return state == GLFW_PRESS || state == GLFW_REPEAT;
}

void MouseEvent::mousePosCallback(double* xpos, double* ypos)
{
    glfwGetCursorPos(this->window->getWindow(), xpos, ypos);
}
