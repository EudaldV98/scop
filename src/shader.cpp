/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:45:17 by jvaquer           #+#    #+#             */
/*   Updated: 2023/01/13 14:01:54 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/shader.hpp"

// Aux function to read content from specific file for .frag and .vert
std::string		get_file_contents(const char *filename)
{
	std::ifstream	in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader()
{
}

void	Shader::construct(const char *vertexFile, const char *fragmentFile)
{
	std::string	vertexCode = get_file_contents(vertexFile);
	std::string	fragmentCode = get_file_contents(fragmentFile);
	const char	*vertexSource = vertexCode.c_str();
	const char	*fragmentSource = fragmentCode.c_str();

	this->vertex_shader(vertexSource);
	this->fragment_shader(fragmentSource);
	this->link_shaders();
}

// vertex shader
void	Shader::vertex_shader(const char *vertexSource)
{
	this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(this->vertexShader, 1, &vertexSource, NULL);
	glCompileShader(this->vertexShader);
	
	// check for shader compile errors
	int success;
	char infoLog[512];
	
	glGetShaderiv(this->vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(this->vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

// fragment shader
void	Shader::fragment_shader(const char *fragmentSource)
{
	this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(this->fragmentShader, 1, &fragmentSource, NULL);
	glCompileShader(this->fragmentShader);

	// check for shader compile errors
	int		success;
	char	infoLog[512];

	glGetShaderiv(this->fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(this->fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

// link shaders
void	Shader::link_shaders()
{
	this->id = glCreateProgram();
	glAttachShader(this->id, this->vertexShader);
	glAttachShader(this->id, this->fragmentShader);
	glLinkProgram(this->id);
	
	// check for linking errors
	int		success;
	char	infoLog[512];
	
	glGetProgramiv(this->id, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(this->id, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void	Shader::activate_shader()
{
	glUseProgram(this->id);
}

void	Shader::delete_shader()
{
	glDeleteProgram(this->id);
}

Shader::~Shader()
{
}