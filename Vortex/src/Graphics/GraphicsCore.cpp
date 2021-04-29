#include "GraphicsCore.h"

namespace vtx::gfx {
	void InitOpenGL()
	{
		glewExperimental = GL_TRUE;
		if (glewInit() != GLEW_OK)
		{
			printf("Error: Could not initialize Glew - OpenGL");
		}

		glEnable(GL_DEPTH_TEST);
	}

	void Wireframe(bool b)
	{
		if (!b)
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		else if (b)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}
}