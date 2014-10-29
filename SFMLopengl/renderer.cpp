#include <iostream>
#include <GL/glew.h>
#include "renderer.h"
#include "common.h"

renderer* renderer::renderer_ = 0;

renderer* renderer::getInstance() {
	if (!renderer_) {
		renderer_ = new renderer();
		renderer_->initialize();
	}
	return renderer_;
}

void renderer::initialize() {
	if (!window_.isOpen()) {
		// Init and test GL Wrangler
		GLenum err = glewInit();
		
		if (GLEW_OK != err) {
			std::cout << "GLEW init error!" << std::endl;
		} else {
			std::cout << "GLEW init success!" << std::endl;
		}

		window_.create(sf::VideoMode(800, 600), "My renderer window!");
		programID_ = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
	}
}

bool renderer::isWindowOpen() {
	return window_.isOpen();
}

void renderer::update(sf::Time elapsed) {
	// GL-code start for triangle
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	// Use our shader
	glUseProgram(programID_);
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

	window_.display();
	while (window_.pollEvent(event_)) {
		switch (event_.type) {
		case sf::Event::Closed:
			window_.close();
			break;
		case sf::Event::Resized:
			// Resize viewport
			glViewport(0, 0, event_.size.width, event_.size.height);
			break;
		}
	}
	lastUpdateTime_ = elapsed;
}