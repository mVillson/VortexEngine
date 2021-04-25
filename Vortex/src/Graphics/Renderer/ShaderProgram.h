#pragma once

#include "..\GraphicsCore.h"

#include <string>
#include <fstream>
#include <sstream>

// Math library
#include "..\..\Vendor\glm\glm.hpp"
using namespace glm;
#include "..\..\Vendor\glm\gtc\matrix_transform.hpp"
#include "..\..\Vendor\glm\gtc\constants.hpp"
#include "..\..\Vendor\glm\gtc\type_ptr.hpp"

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
		void SetUniform(const std::string& name, const int v);
		void SetUniform(const std::string& name, const vec2& v);
		void SetUniform(const std::string& name, const vec3& v);
		void SetUniform(const std::string& name, const vec4& v);
		void SetUniformMatrix(const std::string& name, const mat4& m);
	};
}