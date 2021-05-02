#include "ShaderProgram.h"

namespace vtx
{
	std::string VORTEX_API FileToString(std::string& filepath)
	{
		std::ifstream file(filepath);
		std::stringstream ss;

		std::string line;
		while (getline(file, line))
		{
			ss << line << "\n";
		}

		return ss.str();
	}
}

namespace vtx::gfx
{
	ShaderProgram::ShaderProgram(std::string VSfilepath, std::string FSfilepath)
	{
		mProgram = glCreateProgram();

		GLuint vs = CreateShader(GL_VERTEX_SHADER, FileToString(VSfilepath).c_str());
		GLuint fs = CreateShader(GL_FRAGMENT_SHADER, FileToString(FSfilepath).c_str());

		glAttachShader(mProgram, vs);
		glAttachShader(mProgram, fs);

		glLinkProgram(mProgram);
		glValidateProgram(mProgram);
		glUseProgram(mProgram);

		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	ShaderProgram::ShaderProgram()
		:mProgram(0)
	{

	}

	void ShaderProgram::Create(std::string VSfilepath, std::string FSfilepath)
	{
		mProgram = glCreateProgram();

		GLuint vs = CreateShader(GL_VERTEX_SHADER, FileToString(VSfilepath).c_str());
		GLuint fs = CreateShader(GL_FRAGMENT_SHADER, FileToString(FSfilepath).c_str());

		glAttachShader(mProgram, vs);
		glAttachShader(mProgram, fs);

		glLinkProgram(mProgram);
		glValidateProgram(mProgram);
		glUseProgram(mProgram);

		glDeleteShader(vs);
		glDeleteShader(fs);
	}

	unsigned int ShaderProgram::CreateShader(GLenum type, const char* ShaderSource)
	{
		GLuint id = glCreateShader(type);
		glShaderSource(id, 1, &ShaderSource, nullptr);
		
		glCompileShader(id);
		// Todo - Error Handling

		return id;
	}

	void ShaderProgram::Bind() const
	{
		glUseProgram(mProgram);
	}

	void ShaderProgram::Unbind() const
	{
		glUseProgram(mProgram);
	}

	// Uniform Setters
	void ShaderProgram::SetUniform(const std::string& name, int v)
	{
		glUniform1i(GetUniformLocation(name), v);
	}

	void ShaderProgram::SetUniform(const std::string& name, const vec2& v)
	{
		glUniform2f(GetUniformLocation(name), v.x, v.y);
	}

	void ShaderProgram::SetUniform(const std::string& name, const vec3& v)
	{
		glUniform3f(GetUniformLocation(name), v.x, v.y, v.z);
	}

	void ShaderProgram::SetUniform(const std::string& name, const vec4& v)
	{
		glUniform4f(GetUniformLocation(name), v.x, v.y, v.z, v.w);
	}

	void ShaderProgram::SetUniformMatrix(const std::string& name, const mat4& m)
	{
		glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, value_ptr(m));
	}

	// GetUniformLocation
	unsigned int ShaderProgram::GetUniformLocation(const std::string& name)
	{
		if (mUniformLocationCache.find(name) != mUniformLocationCache.end())
			return mUniformLocationCache[name];

		unsigned int location = glGetUniformLocation(mProgram, name.c_str());
		if (location == -1)
		{
			printf("Warning: Uniform '%s' does not exist!\n", name.c_str());
		}

		mUniformLocationCache[name] = location;
		return location;
	}

}