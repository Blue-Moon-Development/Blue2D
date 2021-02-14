#include <utility>

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
 * File Name: BlueException.h
 * Date File Created: 02/14/2021 at 3:01 PM
 * Author: Matt
 */

#ifndef BLUE2D_BLUEEXCEPTION_H
#define BLUE2D_BLUEEXCEPTION_H


class BlueException : public std::exception
{
public:
	BlueException(const int line, const char* file, std::string info) :
			mLine(line), mFile(file), mInfo(std::move(info)) { }
			
	const char * what() const override;
	
	virtual const char* getType() const;
	std::string getOrigin() const;
	
	int getLine() const { return mLine; }
	const std::string& getFile() const { return mFile; }
	
protected:
	
	virtual const char* getName() const;
	
	mutable std::string mWhat;
	mutable std::string mType;
	std::string mInfo;
private:
	int mLine;
	std::string mFile;
};

class ShaderException : public BlueException
{
public:
	ShaderException(int line, const char* file, std::string info) : BlueException(line, file, std::move(info)) {}
	
	const char * getName() const override { return "Shader Exception"; }
};


	#define SHADER_EXCEPTION(x) ShaderException(__LINE__, __FILE__, x)


#endif //BLUE2D_BLUEEXCEPTION_H
