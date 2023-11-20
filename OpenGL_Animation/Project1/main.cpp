#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Window.h"
#include "Callbacks.h"
#include "Game.h"



int main(int argc, char* argv[])
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    Window* baseWindow = new Window("Animation Project", 720, 1280);

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

    glfwSetFramebufferSizeCallback(baseWindow->GetWindow(), Callbacks::Framebuffer_size_callback);

    while (!glfwWindowShouldClose(baseWindow->GetWindow()))
    {
        Callbacks::TestInput(baseWindow->GetWindow());

        glClearColor(0.9f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(baseWindow->GetWindow());
        glfwPollEvents();
    }

    glfwTerminate();

	return 0;
}