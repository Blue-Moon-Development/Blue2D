//
// Created by mattr on 2/13/2021.
//

#include <iostream>

#include <blue2d/Blue2D.h>
#include <blue2d/Display.h>
#include <blue2d/Shader.h>
#include <blue2d/MsgBox.h>
#include <blue2d/BlueException.h>

#include <blue2d/Mesh.h>


void run()
{
	std::cout << "Hello world!\n";
	Blue2D::init();
	
	Display display("Test App", 1280, 720);
	
	Shader shader("./assets/shaders/basic.vert", "./assets/shaders/basic.frag");
	
	
	list<Vertex> verts = {
			{ Position { 0.5f, -0.5f },  Color { 1.0f, 0.0f, 0.0f } }, // bottom right
			{ Position { -0.5f, -0.5f }, Color { 0.0f, 1.0f, 0.0f } }, // bottom left
			{ Position { 0.0f, 0.5f },   Color { 0.0f, 0.0f, 1.0f } } // top
	};
	
	
	//@formatter:off
	list<uint> indices = { 0, 1, 2 };
	//@formatter:on
	
	Mesh triangle(verts, indices);


//	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	
	while (!display.isClosed())
	{
		display.clear();
		
		
		triangle.bind();
		
		auto time = static_cast<float>(glfwGetTime());
		float greenTime = ( cos(time) / 2.0f ) + 0.5f;
		float blueTime = ( sin(time) / 2.0f ) + 0.5f;
//		float time2 = greenTime * blueTime;
		
		shader.bind();
		shader.setUniform("sinTime", blueTime);
		shader.setUniform("cosTime", greenTime);
//		shader.setUniform("bothTime", time2);
		
		triangle.draw();
		
		display.swap();
	}
}


int main(int argc, char** argv)
{
	
	try
	{
		run();
	} catch (const BlueException& e)
	{
		LOG_CRITICAL(e.what());
		MsgBox::show(e.getType(), e.what(), MsgBox::STYLE_ERROR);
		return -1;
	} catch (const std::exception& e)
	{
		LOG_CRITICAL(e.what());
		MsgBox::show("STD Exception", e.what(), MsgBox::STYLE_ERROR);
		return -1;
	}
	catch (...)
	{
		LOG_CRITICAL("Encountered an unknown fatal exception");
		MsgBox::show("Unknown Exception", "No details available. "
										  "Potentially a pointer to an exception was thrown.\n"
										  "Do not use `throw new exception();` only `throw exception();`",
					 MsgBox::STYLE_ERROR);
		return -1;
	}
	
	return 0;
}
