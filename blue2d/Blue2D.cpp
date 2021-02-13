//
// Created by mattr on 2/13/2021.
//

#include "Blue2D.h"
#include <iostream>
#include <fmt/core.h>

void Blue2D::init()
{
	std::string test = fmt::format("This {} is just a test", 32);
	std::cout << "Blue2D init\n" << test << std::endl;
}