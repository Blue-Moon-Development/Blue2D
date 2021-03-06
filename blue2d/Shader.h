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
 * File Name: Shader.h
 * Date File Created: 02/13/2021 at 5:53 PM
 * Author: Matt
 */

#ifndef BLUE2D_SHADER_H
#define BLUE2D_SHADER_H

#include "Bindable.h"

class Shader : public Bindable
{
public:
	Shader(std::string vert, std::string frag);
	void bind() override;
	
	void setUniform(const std::string& name, const mat4f& value);
	void setUniform(const std::string& name, const vec4f& value);
	void setUniform(const std::string& name, const vec3f& value);
	void setUniform(const std::string& name, const vec2f& value);
	void setUniform(const std::string& name, float value);
	void setUniform(const std::string& name, int value);
	void setUniform(const std::string& name, uint value);
	
	
private:
	[[nodiscard]] int getUniformLocation(const std::string& name) const;
	[[nodiscard]] int getAttributeLocation(const std::string& name) const;
	std::string mVertPath;
	std::string mFragPath;
	uint mProgram;
};


#endif //BLUE2D_SHADER_H
