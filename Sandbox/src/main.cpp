#include <VortexEngine.h>

#include <iostream>

float vertices[] = {
	-0.5f, -0.5f, //0.0f, 0.0f, // bottom  left   0
	-0.5f,  0.5f, //0.0f, 0.0f, // top	 left   1
	 0.5f,  0.5f, //0.0f, 0.0f, // top     right  2
	 0.5f, -0.5f //0.0f, 0.0f  // bottom  right  3
};

unsigned int indices[] = {
	0, 1, 2,
	2, 3, 0,
};

vtx::Window gWindow;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void FrameBuffersizeCallback(GLFWwindow* window, int width, int height);

class App : public vtx::Application
{
public:
	vtx::gfx::VertexArray va;
	vtx::gfx::VertexBuffer vb;
	vtx::gfx::IndexBuffer ib;
	vtx::gfx::Renderer renderer;
	vtx::gfx::ShaderProgram shaderprogram;
	vtx::gfx::VertexBufferLayout layout;
	void OnStart()
	{
		vtx::gfx::InitOpenGL();
		gWindow.VSync();

		renderer.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		
		InputEvent.SetWindow(&gWindow);
		InputEvent.SetKeyCallbackFunction(KeyCallback);
		WindowEvent.SetWindow(&gWindow);
		WindowEvent.SetFrameBuffersizeCallback(FrameBuffersizeCallback);
		
		va.Create();
		vb.Create(vertices, 3 * 5 * sizeof(vertices));
		ib.Create(indices, 9);
		
		layout.Create<float>(2);

		shaderprogram.Create("src/res/vert.shader", "src/res/frag.shader");
	}

	void Update(float fElapsedTime)
	{
		// Random
		static float r = 0;
		static float increment = 0.005f;
		r += increment;

		if (r >= 1.0f)
		{
			increment = -0.005f;
		}
		else if (r <= 0.0f)
		{
			increment = 0.005f;
		}

		// Set Uniforms
		shaderprogram.SetUniform("uColor", r, 0.0f, 0.0f, 0.5f);

		// Render
		renderer.Draw(va, vb, ib, shaderprogram);
		gWindow.Update();
	}
	
	void OnDestroy()
	{
		printf("Stopping...");
	}
};

// Callbacks
void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// Key Escape
	if (key == KeyCode.ESCAPE)
		gWindow.SetWindowShouldClose();

	// Key W
	if (key == KeyCode.W && action == Action.PRESS)
	{
		
		static bool wireframe = false;
		wireframe = !wireframe;
		if (!wireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else if (wireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}

void FrameBuffersizeCallback(GLFWwindow* window, int width, int height)
{
	gWindow.SetWidth(width);
	gWindow.SetHeight(height);
	gWindow.Viewport(0, 0, gWindow.GetWidth(), gWindow.GetHeight());
}

// Main Function
int main()
{
	App app;
	gWindow.Construct(800, 600, "OpenGL Window!");
	app.SetCloseWindow(&gWindow);
	app.Run();
}