#pragma once

#include "../Core/Core.h"

#include <GL/glew.h>

#include <glfw3.h>

namespace vtx {

	class VORTEX_API Window
	{
	private:
		GLFWwindow* mWindow = NULL;

		int mWidth, mHeight;
		const char* mTitle;
		bool mVSync = true;
		bool mWindowIsClosed = false;

	public:
		Window();
		Window(int width, int height, const char* title);
		void Construct(int width, int height, const char* title);
		void Update();
		void MakeContextCurrent();
		void VSync(bool vsync = true);

		void Viewport(int x, int y, int width, int height);

		// Getters
		int GetWindowShouldClose();
		GLFWwindow* GetWindow();
		int GetWidth() { return mWidth; }
		int GetHeight() { return mHeight; }

		// Setters
		void SetWindowShouldClose();
		void SetTitle(const char* title);
		void SetWidth(int width);
		void SetHeight(int height);
	};

}
