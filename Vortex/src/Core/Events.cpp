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
}