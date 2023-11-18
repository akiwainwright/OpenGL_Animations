#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Window.h"
#include "Game.h"

int main(int argc, char* argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window* baseWindow = new Window("Animation Project", 600, 600);

    if (!baseWindow->CreateWindow())
    {
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(baseWindow->GetWindow());

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glViewport(0, 0, baseWindow->GetWindowWidth(), baseWindow->GetWindowHeight());



	return 0;
}