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
 * File Name: BlueException.cpp.cc
 * Date File Created: 02/14/2021 at 3:01 PM
 * Author: Matt
 */

#include "BlueException.h"

const char* BlueException::what() const
{
	mWhat = fmt::format("{}\n{}\n[Info]\n{}", getType(), getOrigin(), mInfo);
	return mWhat.c_str();
}

std::string BlueException::getOrigin() const
{
	return fmt::format("[File] {}\n[Line] {}", mFile, mLine);
}

const char* BlueException::getType() const
{
	mType = fmt::format("Blue2D#{}", getName());
	return mType.c_str();
}

const char* BlueException::getName() const
{
	return "Blue2D General Exception";
}
