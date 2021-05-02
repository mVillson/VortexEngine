#pragma once

#include "..\GraphicsCore.h"

#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>

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
	class ShaderProgram
	{
	private:
		GLuint mProgram;
		std::unordered_map<std::string, int> mUniformLocationCache;

		unsigned int CreateShader(GLenum type, const char* ShaderSource);
		unsigned int GetUniformLocation(const std::string& name);
	public:
		VORTEX_API ShaderProgram(std::string VSfilepath, std::string FSfilepath);
		VORTEX_API ShaderProgram();
		void VORTEX_API Create(std::string VSfilepath, std::string FSfilepath);

		void VORTEX_API Bind() const;
		void VORTEX_API Unbind() const;

		// Uniform Setters
		void VORTEX_API SetUniform(const std::string& name, const int v);
		void VORTEX_API SetUniform(const std::string& name, const vec2& v);
		void VORTEX_API SetUniform(const std::string& name, const vec3& v);
		void VORTEX_API SetUniform(const std::string& name, const vec4& v);
		void VORTEX_API SetUniformMatrix(const std::string& name, const mat4& m);
	};
}