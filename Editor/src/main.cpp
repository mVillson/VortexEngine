#include <VortexEngine.h>

#include <iostream>

float vertices[] = {
	// position			 // tex coords
	// 
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

vec3 cubePos(0.0f, 0.0f, -5.0f);

vtx::Window gWindow;

vtx::gfx::OrbitCamera orbitcamera;
float gYaw = 0.0f;
float gPitch = 0.0f;
float gRadius = 10.0f;
const float MOUSE_SENSITIVITY = 0.4f;

float fps;

void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
void FrameBuffersizeCallback(GLFWwindow* window, int width, int height);
void MouseMoveCallback(GLFWwindow* window, double posX, double posY);
void MouseScrollCallback(GLFWwindow* window, double deltaX, double deltaY);

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
		gWindow.VSync(false);
		renderer.SetClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		
		// Setting up events
		Event.SetWindow(&gWindow);
		Event.SetKeyCallbackFunction(KeyCallback);
		Event.SetMouseMoveCallbackFunction(MouseMoveCallback);
		Event.SetMouseScrollCallbackFunction(MouseScrollCallback);
		Event.SetFrameBuffersizeCallback(FrameBuffersizeCallback);

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

		orbitcamera.SetLookAt(cubePos);
	}

	void Update(float fElapsedTime)
	{
		mat4 model(1.0), view(1.0), projection(1.0);

		orbitcamera.Rotate(gYaw, gPitch);
		orbitcamera.SetRadius(gRadius);

		model = translate(model, cubePos);

		view = orbitcamera.GetViewMatrix();

		projection = perspective(radians(45.0f), (float)gWindow.GetWidth() / (float)gWindow.GetHeight(), 0.1f, 100.0f);

		mat4 mvp = projection * view * model;
		shaderprogram.SetUniformMatrix("uMVP", mvp);

		// fps
		fps = 1.0f / fElapsedTime;
		static int i = 0;
		i+=1;
		if (i >= 2500)
		{
			std::stringstream ss;
			ss << "Vortex Editor - fps: " << fps;
			gWindow.SetTitle(ss.str().c_str());
			i = 0;
		}

		// Render
		renderer.Draw(va, vb, shaderprogram, 36);
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
	if (key == KeyCode::ESCAPE)
		gWindow.SetWindowShouldClose();

	// Key Function
	if (key == KeyCode::F1 && action == Action::PRESS) {
		static bool wireframe = false;
		wireframe = !wireframe;
		if (!wireframe)
			vtx::gfx::Wireframe(false);
		else if (wireframe)
			vtx::gfx::Wireframe(true);
	}
}

void MouseMoveCallback(GLFWwindow* window, double posX, double posY)
{
	static vec2 lastMousePos = vec2(0, 0);

	if (Event.GetRightMouseButtonDown())
	{
		gYaw -= ((float)posX - lastMousePos.x) * MOUSE_SENSITIVITY;
		gPitch += ((float)posY - lastMousePos.y) * MOUSE_SENSITIVITY;
	}

	lastMousePos.x = (float)posX;
	lastMousePos.y = (float)posY;
}

void MouseScrollCallback(GLFWwindow* window, double deltaX, double deltaY)
{
	if (Event.GetRightMouseButtonDown())
	{
		gRadius += -(float)deltaY;
		gRadius = clamp(gRadius, 0.0f, 80.0f);
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