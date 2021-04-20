#pragma once

#include "..\GraphicsCore.h"

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
		ShaderProgram(std::string VSfilepath, std::string FSfilepath);
		ShaderProgram();
		void Create(std::string VSfilepath, std::string FSfilepath);

		void Bind() const;
		void Unbind() const;

		// Uniform Setters
		void SetUniform(const std::string& name, float v0, float v1, float v2, float v3);
		void SetUniform(const std::string& name, float v0, float v1, float v2);
	};
}