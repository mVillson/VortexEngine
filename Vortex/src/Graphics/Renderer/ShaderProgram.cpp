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
	void ShaderProgram::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		int location = glGetUniformLocation(mProgram, name.c_str());
		glUniform4f(location, v0, v1, v2, v3);
	}

	void ShaderProgram::SetUniform3f(const std::string& name, float v0, float v1, float v2)
	{
		int location = glGetUniformLocation(mProgram, name.c_str());
		glUniform3f(location, v0, v1, v2);
	}

	void ShaderProgram::SetUniform1i(const std::string& name, int v)
	{
		int location = glGetUniformLocation(mProgram, name.c_str());
		glUniform1i(location, v);
	}

	void ShaderProgram::SetUniformVector(const std::string& name, vec3 v)
	{
		int location = glGetUniformLocation(mProgram, name.c_str());
		glUniform3f(location, v.x, v.y, v.z);
	}

	void ShaderProgram::SetUniformVector(const std::string& name, vec4 v)
	{
		int location = glGetUniformLocation(mProgram, name.c_str());
		glUniform4f(location, v.x, v.y, v.z, v.w);
	}

	void ShaderProgram::SetUniformMatrix(const std::string& name, mat4 m)
	{
		int location = glGetUniformLocation(mProgram, name.c_str());
		glUniformMatrix4fv(location, 1, GL_FALSE, value_ptr(m));
	}
}