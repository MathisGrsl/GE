#include "ge.hpp"

void mouse_callback(GLFWwindow *window, double xpos, double ypos)
{
    ge::mouseX = xpos;
    ge::mouseY = ypos;

    ge::moveCamera(xpos - ge::screenWidth / 2, ypos - ge::screenHeight / 2);
    glfwSetCursorPos(window, ge::screenWidth / 2, ge::screenHeight / 2);
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    window = window;
    glViewport(0, 0, width, height);

    ge::screenWidth = width;
    ge::screenHeight = height;
}

void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    ge::handleKey(key, action);
}

void button_callback(GLFWwindow *window, int button, int action, int mods)
{
    ge::handleMouseButton(button, action);
}

