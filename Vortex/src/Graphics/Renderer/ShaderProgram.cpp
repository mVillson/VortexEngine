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
}