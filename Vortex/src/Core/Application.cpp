#include "Application.h"

namespace vtx {

	Application::Application()
	{
		InitGLFW();
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		OnStart();

		double LastTime = 0.0;
		double deltaTime = 0.0;
		double Time = 0.0;
		while (!mWindow->GetWindowShouldClose())
		{
			Update((float)deltaTime);
			Time = glfwGetTime();
			deltaTime = Time - LastTime;
			LastTime = glfwGetTime();
		}

		OnDestroy();
	}

	void Application::InitGLFW()
	{
		if (!glfwInit())
		{
			printf("Error: Could not initialize Glfw!");
		}
	}

	// Setters
	void Application::SetCloseWindow(Window* window)
	{
		mWindow = window;
	}
}