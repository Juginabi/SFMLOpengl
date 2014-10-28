#include <iostream>
#include <GL\glew.h>
#include <SFML\OpenGL.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include "common.h"

int main(int args, char* argv[]) {

	std::cout << "SFML and GLEW testing!" << std::endl;

	// Clock for timing 'gameloop'
	sf::Clock clock;

	// Create SFML window which creates opengl context
	sf::Window window(sf::VideoMode(800, 600), "This is SFML openGL window!");
	
	// Init and test GL Wrangler
	GLenum err = glewInit();
	if (GLEW_OK != err) {
		std::cout << "GLEW init error!" << std::endl;
	} else {
		std::cout << "GLEW success!" << std::endl;
	}

	// Create sfml event object
	sf::Event event;

	// Create and compile our GLSL program from the shaders
	GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

	// start infinite while loop
	while (window.isOpen()) {

		// GL-code start for triangle
		GLuint VertexArrayID;
		glGenVertexArrays(1, &VertexArrayID);
		glBindVertexArray(VertexArrayID);
		// Use our shader
		glUseProgram(programID);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// An array of 3 vectors which represents 3 vertices
		static const GLfloat g_vertex_buffer_data[] = {
		   -1.0f, -1.0f, 0.0f,
		   1.0f, -1.0f, 0.0f,
		   0.0f,  1.0f, 0.0f,
		};

		// This will identify our vertex buffer
		GLuint vertexbuffer;
 
		// Generate 1 buffer, put the resulting identifier in vertexbuffer
		glGenBuffers(1, &vertexbuffer);
 
		// The following commands will talk about our 'vertexbuffer' buffer
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
 
		// Give our vertices to OpenGL.
		glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
		   0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		   3,                  // size
		   GL_FLOAT,           // type
		   GL_FALSE,           // normalized?
		   0,                  // stride
		   (void*)0            // array buffer offset
		);
 
		// Draw the triangle !
		
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
 
		glDisableVertexAttribArray(0);

		// GL-code end for triangle

		// Swap draw buffer to window
		window.display();

		// Check for events
		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:
				window.close();
			case sf::Event::Resized:
				// Resize viewport
				glViewport(0, 0, event.size.width, event.size.height);
				break;
			}
		}
		sf::sleep(sf::milliseconds(16) - clock.getElapsedTime());
		clock.restart();
	}
	
	return EXIT_SUCCESS;

}