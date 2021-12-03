#include "Shader.h"

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>


#include"Renderer.h"

//Constructor
Shader::Shader(const std::string& filepath)
	:m_FilePath(filepath), m_RendererID(0)
{
	shaderProgramSource source = ParseShader(filepath);
	m_RendererID = CreateShader(source.vertex_source, source.fragment_source);
}

//Destructor
Shader::~Shader()
{
	GlCall(glDeleteProgram(m_RendererID));
}


//
shaderProgramSource Shader::ParseShader(const std::string& filepath)
{
	std::ifstream fin(filepath);

	enum class shaderType {
		NONE = -1,
		VERTEX = 0,
		FRAGMENT = 1
	};

	std::string line;
	std::stringstream ss[2];
	shaderType type = shaderType::NONE;
	while (getline(fin, line))
	{
		if (line.find("#shader") != std::string::npos)
		{
			if (line.find("vertex") != std::string::npos)
			{
				type = shaderType::VERTEX;
			}
			else if (line.find("fragment") != std::string::npos)
			{
				type = shaderType::FRAGMENT;
			}
		}
		else
		{
			ss[(int)type] << line << '\n';
		}
	}

	return { ss[0].str(),ss[1].str() };
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source)
{
	GlCall(unsigned int id = glCreateShader(type));
	const char* src = source.c_str();
	GlCall(glShaderSource(id, 1, &src, nullptr));
	GlCall(glCompileShader(id));

	//Error handling
	int result;
	GlCall(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE)
	{
		int lenght;
		GlCall(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght));
		char* message = (char*)alloca(lenght * sizeof(char));
		GlCall(glGetShaderInfoLog(id, lenght, &lenght, message));
		std::cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? " vertex" : " fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		GlCall(glDeleteShader(id));
		return 0;
	}

	return id;
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentshader)
{
	GlCall(unsigned int program = glCreateProgram());
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentshader);

	GlCall(glAttachShader(program, vs));
	GlCall(glAttachShader(program, fs));
	GlCall(glLinkProgram(program));
	GlCall(glValidateProgram(program));

	GlCall(glDeleteShader(vs));
	GlCall(glDeleteShader(fs));
	
	 return program;
}


//Methods
void Shader::Bind() const
{
	GlCall(glUseProgram(m_RendererID));
}

void Shader::Unbind()const
{
	GlCall(glUseProgram(0));
}


//Set uniforms
void Shader::SetUniform1i(const std::string& name, int value)
{
	GlCall(glUniform1i(GetUniformLocation(name), value));
}

void Shader::SetUniform1f(const std::string& name, float value)
{
	GlCall(glUniform1f(GetUniformLocation(name), value));
}

void Shader::SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
	GlCall(glUniform4f(GetUniformLocation(name), v0, v1, v2, v3));
}

void Shader::SetUniformMat4f(const std::string& name, const glm::mat4& matrix)
{
	GlCall(glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, &matrix[0][0]));
}

 int Shader::GetUniformLocation(const std::string& name)
{
	if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
	{
		return m_UniformLocationCache[name];
	}

	GlCall(int location = glGetUniformLocation(m_RendererID, name.c_str()));
	if (location == -1)
		std::cout << "Warning: uniform " << name << " doesn't exist!" << std::endl;

	m_UniformLocationCache[name] = location;
	return location;
}

