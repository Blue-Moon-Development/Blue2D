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
#include "BlueException.h"

#include <gl/glew.h>
#include <glm/gtc/type_ptr.hpp>

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
		std::string err = fmt::format("Vertex Shader Error [{}]: {}", mVertPath, info);
		throw SHADER_EXCEPTION(err);
	}
	
	uint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragSrc, nullptr);
	glCompileShader(fragShader);
	
	glGetShaderiv(fragShader, GL_COMPILE_STATUS, &success);
	
	if(!success)
	{
		glGetShaderInfoLog(fragShader, 512, nullptr, info);
		std::string err = fmt::format("Fragment Shader Error [{}]: {}", mFragPath, info);
		throw SHADER_EXCEPTION(err);
	}
	
	mProgram = glCreateProgram();
	glAttachShader(mProgram, vertShader);
	glAttachShader(mProgram, fragShader);
	glLinkProgram(mProgram);
	
	glGetShaderiv(mProgram, GL_LINK_STATUS, &success);
	if(!success)
	{
		glGetShaderInfoLog(mProgram, 512, nullptr, info);
		std::string err = fmt::format("Shader Linkage Error [{} & {}]: {}", mVertPath, mFragPath, info);
		throw SHADER_EXCEPTION(err);
	}
	
	// TODO: Throw exceptions after critical logs, show window box on capture like in Mage3DX
	
	LOG_INFO("Shader [id={}] loaded from files [{}] and [{}]", mProgram, mVertPath, mFragPath);
}

void Shader::bind()
{
	glUseProgram(mProgram);
}

int Shader::getUniformLocation(const std::string& name) const
{
	return glGetUniformLocation(mProgram, name.c_str());
}

int Shader::getAttributeLocation(const std::string& name) const
{
	return glGetAttribLocation(mProgram, name.c_str());
}

void Shader::setUniform(const std::string& name, const vec4f& value)
{
	glUniform4f(getUniformLocation(name), value.x, value.y, value.z, value.w);
}

void Shader::setUniform(const std::string& name, float value)
{
	glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform(const std::string& name, const mat4f& value)
{
	glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::setUniform(const std::string& name, const vec3f& value)
{
	glUniform3f(getUniformLocation(name), value.x, value.y, value.z);
}

void Shader::setUniform(const std::string& name, const vec2f& value)
{
	glUniform2f(getUniformLocation(name), value.x, value.y);
}

void Shader::setUniform(const std::string& name, int value)
{
	glUniform1i(getUniformLocation(name), value);
}

void Shader::setUniform(const std::string& name, uint value)
{
	glUniform1ui(getUniformLocation(name), value);
}
