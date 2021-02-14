/*
 * Blue2D
 * Copyright (C) 2021 Blue Moon Development. All rights reserved.
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 * Contact: team@bluemoondev.org
 * 
 * File Name: Shader.cpp.cc
 * Date File Created: 02/13/2021 at 5:53 PM
 * Author: Matt
 */

#include "Shader.h"
#include "Util.h"
#include <gl/glew.h>

Shader::Shader(std::string vert, std::string frag):
		mVertPath(std::move(vert)),
		mFragPath(std::move(frag))
{
	auto vertSrcStr = read_file(mVertPath);
	auto fragSrcStr = read_file(mFragPath);
	
	const char* vertSrc = vertSrcStr.c_str();
	const char* fragSrc = fragSrcStr.c_str();
	
	uint vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &vertSrc, nullptr);
	glCompileShader(vertShader);
	int success;
	char info[512];
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
	
	if(!success)
	{
		glGetShaderInfoLog(vertShader, 512, nullptr, info);
		std::cerr << "Vertex Shader Error: " << info << std::endl;
	}
	
	uint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragSrc, nullptr);
	glCompileShader(fragShader);
	
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	
	if(!success)
	{
		glGetShaderInfoLog(fragShader, 512, nullptr, info);
		std::cerr << "Frag Shader Error: " << info << std::endl;
	}
	
	mProgram = glCreateProgram();
	glAttachShader(mProgram, vertShader);
	glAttachShader(mProgram, fragShader);
	glLinkProgram(mProgram);
	
	glGetShaderiv(mProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(mProgram, 512, nullptr, info);
		std::cerr << "Shader linkage error: " << info << std::endl;
	}
}

Shader::Shader(const char* vertSrc, const char* fragSrc)
{
	uint vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &vertSrc, nullptr);
	glCompileShader(vertShader);
	int success;
	char info[512];
	glGetShaderiv(vertShader, GL_COMPILE_STATUS, &success);
	
	if(!success)
	{
		glGetShaderInfoLog(vertShader, 512, nullptr, info);
		std::cerr << "Vertex Shader Error: " << info << std::endl;
	}
	
	uint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragSrc, nullptr);
	glCompileShader(fragShader);
	
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	
	if(!success)
	{
		glGetShaderInfoLog(fragShader, 512, nullptr, info);
		std::cerr << "Frag Shader Error: " << info << std::endl;
	}
	
	mProgram = glCreateProgram();
	glAttachShader(mProgram, vertShader);
	glAttachShader(mProgram, fragShader);
	glLinkProgram(mProgram);
	
	glGetShaderiv(mProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(mProgram, 512, nullptr, info);
		std::cerr << "Shader linkage error: " << info << std::endl;
	}
	
	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

void Shader::bind()
{
	glUseProgram(mProgram);
}

int Shader::getUniform(const std::string& name) const
{
	return glGetUniformLocation(mProgram, name.c_str());
}

int Shader::getAttribute(const std::string& name) const
{
	return glGetAttribLocation(mProgram, name.c_str());
}