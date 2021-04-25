#include <VortexEngine.h>

#include <iostream>

float vertices[] = {
	 100.0f, 100.0f, 0.0f, 0.0f, // bottom  left   0
	 100.0f, 200.0f, 0.0f, 1.0f, // top	    left   1
	 200.0f, 200.0f, 1.0f, 1.0f,  // top     right  2
	 200.0f, 100.0f, 1.0f, 0.0f	 // bottom  right  3
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
private:
	vtx::gfx::VertexArray va;
	vtx::gfx::VertexBuffer vb;
	vtx::gfx::IndexBuffer ib;
	vtx::gfx::VertexBufferLayout layout;
	vtx::gfx::Renderer renderer;
	vtx::gfx::ShaderProgram shaderprogram;
	vtx::gfx::Texture texture;
	
	mat4 mvp;
	mat4 model;
	mat4 view;
	mat4 projection;

	void OnStart()
	{
		//initialize opengl
		vtx::gfx::InitOpenGL();

		// setting up renderer and window things
		gWindow.VSync();
		renderer.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		
		// Setting up events
		InputEvent.SetWindow(&gWindow);
		InputEvent.SetKeyCallbackFunction(KeyCallback);
		WindowEvent.SetWindow(&gWindow);
		WindowEvent.SetFrameBuffersizeCallback(FrameBuffersizeCallback);
		
		// creating buffers
		va.Create();
		vb.Create(vertices, 4 * 4 * sizeof(float));
		layout.Push<float>(2);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);
		ib.Create(indices, 9);

		// Setting up Model View Projection
		projection = ortho(0.0f, (float)gWindow.GetWidth(), 0.0f, (float)gWindow.GetHeight(), -1.0f, 1.0f);
		view = translate(mat4(1.0f), vec3(-100, -100, 0));
		model = translate(mat4(1.0f), vec3(200, 200, 0));

		mvp = projection * view * model;

		// Creating shaders
		shaderprogram.Create("res/shaders/vert.shader", "res/shaders/frag.shader");

		shaderprogram.SetUniformMatrix("uMVP", mvp);

		// Texture
		texture.Create("res/textures/villson.jpg");
		texture.Bind();
		shaderprogram.SetUniform("uTexture", 0);
	}

	void Update(float fElapsedTime)
	{
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

	// Key Function 1
	if (key == KeyCode.F1 && action == Action.PRESS) {
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
	gWindow.Construct(960, 540, "OpenGL Window!");
	app.SetCloseWindow(&gWindow);
	app.Run();
}