//
// Created by mattr on 2/13/2021.
//

#include <iostream>

#include <blue2d/Blue2D.h>
#include <blue2d/Display.h>
#include <blue2d/Shader.h>

static const char* vertex_shader_text =
		"#version 330\n"
		"layout (location = 0) in vec3 pos;\n"
		"out vec4 vertColor;\n"
		"\n"
		"\n"
		"void main()\n"
		"{\n"
		"    gl_Position = vec4(pos, 1.0);\n"
		"    vertColor = vec4(0.5, 0.0, 0.0, 1.0);\n"
		"}\n";

static const char* fragment_shader_text =
		"#version 330\n"
		"out vec4 fragColor;\n"
		"in vec4 vertColor;\n"
		"void main()\n"
		"{\n"
		"    fragColor = vertColor;\n"
		"}\n";




int main(int argc, char** argv)
{
	std::cout << "Hello world!\n";
	Blue2D::init();
	
	Display display("Test App", 1280, 720);
	
	Shader shader(vertex_shader_text, fragment_shader_text);
	
	float vertices[] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left
	};
	
	uint indices[] = {
			0, 1, 3, // first triangle
			1, 2, 3 // second triangle
	};
	
	
	uint vbo, vao, ebo;
	glGenVertexArrays(1, &vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	
	while(!display.isClosed())
	{
		display.clear();
		
		
		glBindVertexArray(vao);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)nullptr);
		glEnableVertexAttribArray(0);
		
		shader.bind();
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
//		glDrawArrays(GL_TRIANGLES, 0, 3); // no ebo
		glBindVertexArray(0);
		
		display.swap();
	}
	
	return 0;
}
