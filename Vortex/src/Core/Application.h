#pragma once

#include <GL/glew.h>
#include <glfw3.h>

#include "..\Core\Core.h"
#include "..\Graphics\GraphicsCore.h"

#include "Window.h"

namespace vtx {

	class VORTEX_API Application
	{
	public:

		// Main Functions ----------------------------------------------------------

		Application();
		~Application();
		void Run();

		virtual void OnStart() = 0;
		virtual void Update(float fElapsedTime) = 0;
		virtual void OnDestroy() = 0;

		void SetCloseWindow(Window* window);

	private:

		// Private Variables --------------------------------------------------------
		Window* mWindow = nullptr;

		// Private Functions --------------------------------------------------------
		void InitGLFW();

	};
}
