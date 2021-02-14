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
 * File Name: Util.cpp.cc
 * Date File Created: 02/13/2021 at 8:28 PM
 * Author: Matt
 */

#include "Util.h"

std::string read_file(const std::string& path)
{
	constexpr auto readSize = std::size_t{4096};
	auto stream = std::ifstream(path.data());
	stream.exceptions(std::ios_base::badbit);
	
	auto out = std::string();
	auto buf = std::string(readSize, '\0');
	
	while(stream.read(&buf[0], readSize))
	{
		out.append(buf, 0, stream.gcount());
	}
	
	out.append(buf, 0, stream.gcount());
	
	return out;
}
