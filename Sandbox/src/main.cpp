#include <VortexEngine.h>

#include <iostream>

float vertices[] = {
	// position		 // tex coords

   // front face
   -1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
	1.0f, -1.0f,  1.0f, 1.0f, 0.0f,
	1.0f,  1.0f,  1.0f, 1.0f, 1.0f,
   -1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
   -1.0f, -1.0f,  1.0f, 0.0f, 0.0f,
	1.0f, -1.0f,  1.0f, 1.0f, 0.0f,

	// back face
	-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
	 1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
	-1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	-1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
	 1.0f, -1.0f, -1.0f, 1.0f, 0.0f,

	 // left face
	 -1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	 -1.0f, -1.0f,  1.0f, 1.0f, 0.0f,
	 -1.0f,  1.0f,  1.0f, 1.0f, 1.0f,
	 -1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	 -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
	 -1.0f, -1.0f,  1.0f, 1.0f, 0.0f,

	 // right face
	  1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
	  1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
	  1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
	  1.0f,  1.0f,  1.0f, 0.0f, 1.0f,
	  1.0f, -1.0f,  1.0f, 0.0f, 0.0f,
	  1.0f, -1.0f, -1.0f, 1.0f, 0.0f,

	  // top face
	  -1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	   1.0f,  1.0f,  1.0f, 1.0f, 0.0f,
	   1.0f,  1.0f, -1.0f, 1.0f, 1.0f,
	  -1.0f,  1.0f, -1.0f, 0.0f, 1.0f,
	  -1.0f,  1.0f,  1.0f, 0.0f, 0.0f,
	   1.0f,  1.0f,  1.0f, 1.0f, 0.0f,

	   // bottom face
	   -1.0f, -1.0f,  1.0f, 0.0f, 1.0f,
		1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
		1.0f, -1.0f,  1.0f, 1.0f, 1.0f,
	   -1.0f, -1.0f,  1.0f, 0.0f, 1.0f,
	   -1.0f, -1.0f, -1.0f, 0.0f, 0.0f,
		1.0f, -1.0f, -1.0f, 1.0f, 0.0f,
};

vec3 cubePos(0.0f, 0.0f, -10.0f);

vtx::Window gWindow;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void FrameBuffersizeCallback(GLFWwindow* window, int width, int height);

class App : public vtx::Application
{
private:
	vtx::gfx::VertexArray va;
	vtx::gfx::VertexBuffer vb;
	vtx::gfx::VertexBufferLayout layout;
	vtx::gfx::Renderer renderer;
	vtx::gfx::ShaderProgram shaderprogram;
	vtx::gfx::Texture texture;

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
		vb.Create(vertices, sizeof(vertices));
		layout.Push<float>(3);
		layout.Push<float>(2);
		va.AddBuffer(vb, layout);

		// Creating shaders
		shaderprogram.Create("res/shaders/vert.shader", "res/shaders/frag.shader");

		shaderprogram.Bind();

		// Texture
		texture.Create("res/textures/wooden_crate.jpg");
		texture.Bind();
		shaderprogram.SetUniform("uTexture", 0);
	}

	void Update(float fElapsedTime)
	{
		mat4 model(1.0), view(1.0), projection(1.0);


		static float cubeAngle = 0.0f;
		cubeAngle += 1.0f;
		if (cubeAngle == 360)
			cubeAngle = 0.0f;

		model = translate(model, cubePos) * rotate(model, radians(cubeAngle), vec3(1.0, 1.0, 1.0));

		vec3 camPos(0.0f, 0.0f, 0.0f);
		vec3 targetPos(0.0f, 0.0f, -1.0f);
		vec3 up(0.0f, 1.0f, 0.0f);
		view = lookAt(camPos, targetPos, up);

		projection = perspective(radians(45.0f), (float)gWindow.GetWidth() / (float)gWindow.GetHeight(), 0.1f, 100.0f);

		mat4 mvp = projection * view * model;
		shaderprogram.SetUniformMatrix("uMVP", mvp);

		// Render
		renderer.Draw(va, vb, shaderprogram);
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
			vtx::gfx::Wireframe(false);
		else if (wireframe)
			vtx::gfx::Wireframe(true);
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
	gWindow.Construct(960, 540, "Vortex Editor");
	app.SetCloseWindow(&gWindow);
	app.Run();
}