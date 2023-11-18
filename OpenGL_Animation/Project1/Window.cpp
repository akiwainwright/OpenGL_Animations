#include "Window.h"
#include <iostream>
#include <glad/glad.h>
#include<GLFW/glfw3.h>

Window::Window(std::string name, int height, int width)
{
	m_WindowName = name;
	m_Height = height;
	m_Width = width;

	m_Window = nullptr;
}

Window::~Window()
{
}

bool Window::CreateWindow()
{
	m_Window = glfwCreateWindow(m_Width, m_Height, m_WindowName.c_str(), NULL, NULL);

	if (!m_Window)
	{
		std::cout << "Failed to create window" << std::endl;
		return false;
	}

	return true;
}
