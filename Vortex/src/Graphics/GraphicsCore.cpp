#include "GraphicsCore.h"

namespace vtx::gfx {
	void InitOpenGL()
	{
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			printf("Error: Could not initialize Glew - OpenGL");
		}
	}
}