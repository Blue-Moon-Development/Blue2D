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
 * File Name: Display.cpp.cc
 * Date File Created: 02/13/2021 at 5:15 PM
 * Author: Matt
 */

#include "Display.h"
#include <fmt/core.h>

void glfw_error_callback(int error, const char* desc)
{
	fmt::print("Error {}: {}", error, desc);
}

Display::Display(const std::string& title, int width, int height):
mTitle(title),
mWidth(width),
mHeight(height)
{
	if(!glfwInit())
	{
		fmt::print("Failed to initialize glfw");
		exit(-1);
	}
	
	glfwSetErrorCallback(glfw_error_callback);
	
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	
	mWindow = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
	
	if(!mWindow)
	{
		fmt::print("Failed to create window");
		exit(-1);
	}
	
	int centerX = (glfwGetVideoMode(glfwGetPrimaryMonitor())->width / 2) - (width / 2);
	int centerY = (glfwGetVideoMode(glfwGetPrimaryMonitor())->height / 2) - (height / 2);
	glfwSetWindowPos(mWindow, centerX, centerY);
	
	
	glfwMakeContextCurrent(mWindow);
	
	glfwSwapInterval(VSYNC);
	
	GLenum init = glewInit();
	if(init)
	{
		fmt::print("Failed to initialize glew - {}", glewGetErrorString(init));
		exit(-1);
	}
	
	
}

Display::~Display()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
}

void Display::clear(int red, int green, int blue)
{
	glClearColor(red, green, blue, 255);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Display::swap()
{
	glfwSwapBuffers(mWindow);
	glfwPollEvents();
}

bool Display::isClosed()
{
	return glfwWindowShouldClose(mWindow);
}
