#include "Events.h"

namespace vtx {
	// WindowEvent
	void WindowEvent::SetFrameBuffersizeCallback(void (*callback)(GLFWwindow* window, int width, int height))
	{
		glfwSetFramebufferSizeCallback(mWindow->GetWindow(), callback);
	}

	// InputEvent
	void InputEvent::SetKeyCallbackFunction(void (*callback)(GLFWwindow* window, int key, int scancode, int action, int mods))
	{
		glfwSetKeyCallback(mWindow->GetWindow(), callback);
	}

	bool InputEvent::GetKeyDown(int KeyCode)
	{
		int action = glfwGetKey(mWindow->GetWindow(), KeyCode);
		if (action == GLFW_PRESS)
		{
			return true;
		}
		else if (action != GLFW_PRESS)
		{
			return false;
		}
	}

	bool InputEvent::GetKeyRelease(int KeyCode)
	{
		int action = glfwGetKey(mWindow->GetWindow(), KeyCode);
		if (action == GLFW_RELEASE)
		{
			return true;
		}
		else if (action != GLFW_PRESS)
		{
			return false;
		}
	}
}