#include "Window.h"

namespace vtx {

	Window::Window()
		:mTitle("No Title!"), mWidth(800), mHeight(600)
	{

	}

	Window::Window(int width, int height, const char* title)
	{
		mWidth = width;
		mHeight = height;
		mTitle = title;

		mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
		if (!mWindow)
		{
			printf("Error: Could not create a Window!");
			glfwTerminate();
		}
	}

	void Window::Construct(int width, int height, const char* title)
	{
		mWidth = width;
		mHeight = height;
		mTitle = title;

		mWindow = glfwCreateWindow(mWidth, mHeight, mTitle, NULL, NULL);
		if (!mWindow)
		{
			printf("Error: Could not create a Window!");
			glfwTerminate();
		}

		glfwMakeContextCurrent(mWindow);
	}

	void Window::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	void Window::MakeContextCurrent()
	{
		glfwMakeContextCurrent(mWindow);
	}

	void Window::VSync(bool vsync)
	{
		mVSync = vsync;
		if (mVSync == true)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	void Window::Viewport(int x, int y, int width, int height)
	{
		glViewport(x, y, width, height);
	}

	// Getters
	GLFWwindow* Window::GetWindow()
	{
		return mWindow;
	}

	int Window::GetWindowShouldClose()
	{
		return glfwWindowShouldClose(mWindow);
	}

	// Setters
	void Window::SetWindowShouldClose()
	{
		glfwSetWindowShouldClose(mWindow, true);
	}

	void Window::SetTitle(const char* title)
	{
		mTitle = title;
		glfwSetWindowTitle(mWindow, mTitle);
	}

	void Window::SetWidth(int width)
	{
		mWidth = width; 
	}

	void Window::SetHeight(int height)
	{
		mHeight = height;
	}
}