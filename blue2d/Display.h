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
 * File Name: Display.h
 * Date File Created: 02/13/2021 at 5:15 PM
 * Author: Matt
 */

#ifndef BLUE2D_DISPLAY_H
#define BLUE2D_DISPLAY_H

#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class Display
{
public:
	Display(const std::string& title, int width, int height);
	~Display();
	
	void swap();
	void clear(int red = 0, int green = 0, int blue = 0);
	
	bool isClosed();
	
	static constexpr int VSYNC = 0;
private:
	GLFWwindow* mWindow;
	int mWidth;
	int mHeight;
	std::string mTitle{};
};


#endif //BLUE2D_DISPLAY_H
