#pragma once
#include <string>

class GLFWwindow;

class Window
{
public:
	Window(std::string name, int height, int width);
	~Window();

	inline int GetWindowHeight() { return m_Height; }
	inline int GetWindowWidth() { return m_Width; }
	inline GLFWwindow* GetWindow() { return m_Window; }

	inline void SetWindowHeight(int height) { m_Height = height; }
	inline void SetWindowWidth(int width) { m_Width = width; }

	bool CreateWindow();

private:
	int m_Height;
	int m_Width;

	std::string m_WindowName;

	GLFWwindow* m_Window;


};

