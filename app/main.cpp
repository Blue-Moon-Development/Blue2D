//
// Created by mattr on 2/13/2021.
//

#include <iostream>

#include <blue2d/Blue2D.h>
#include <blue2d/Display.h>

int main(int argc, char** argv)
{
	std::cout << "Hello world!\n";
	Blue2D::init();
	
	Display display("Test App", 1280, 720);
	
	while(!display.isClosed())
	{
		display.clear();
		display.swap();
	}
	
	return 0;
}
