#pragma once

#include "..\..\Core\Core.h"

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>

namespace vtx
{
	std::string VORTEX_API FileToString(std::string& filepath);
}

namespace vtx::gfx
{
	class VORTEX_API ShaderProgram
	{
	private:
		GLuint mProgram;

		unsigned int CreateShader(GLenum type, const char* ShaderSource);
	public:
		ShaderProgram();

		void Create(std::string VSfilepath, std::string FSfilepath);

		void Bind() const;
		void Unbind() const;
	};
}