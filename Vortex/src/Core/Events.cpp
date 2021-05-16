#include "Events.h"

namespace vtx {

	void Event::SetFrameBuffersizeCallback(void (*callback)(GLFWwindow* window, int width, int height))
	{
		glfwSetFramebufferSizeCallback(mWindow->GetWindow(), callback);
	}

	void Event::SetKeyCallbackFunction(void (*callback)(GLFWwindow* window, int key, int scancode, int action, int mods))
	{
		glfwSetKeyCallback(mWindow->GetWindow(), callback);
	}

	void Event::SetMouseMoveCallbackFunction(void (*callback)(GLFWwindow* window, double posX, double posY))
	{
		glfwSetCursorPosCallback(mWindow->GetWindow(), callback);
	}

	void Event::SetMouseScrollCallbackFunction(void (*callback)(GLFWwindow* window, double deltaX, double deltaY))
	{
		glfwSetScrollCallback(mWindow->GetWindow(), callback);
	}

	bool Event::GetKeyDown(int KeyCode)
	{
		int action = glfwGetKey(mWindow->GetWindow(), KeyCode);
		if (action == GLFW_PRESS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Event::GetKeyRelease(int KeyCode)
	{
		int action = glfwGetKey(mWindow->GetWindow(), KeyCode);
		if (action == GLFW_RELEASE)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// mouse input
	bool Event::GetLeftMouseButtonDown()
	{
		int action = glfwGetMouseButton(mWindow->GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
		if (action == GLFW_PRESS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Event::GetRightMouseButtonDown()
	{
		int action = glfwGetMouseButton(mWindow->GetWindow(), GLFW_MOUSE_BUTTON_RIGHT);
		if (action == GLFW_PRESS)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}