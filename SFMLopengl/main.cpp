#include <iostream>
#include <GL\glew.h>
#include <SFML\OpenGL.hpp>
#include <SFML\Window.hpp>
#include <SFML\System.hpp>
#include "common.h"
#include "renderer.h"

int main(int args, char* argv[]) {

	std::cout << "SFML and GLEW testing!" << std::endl;

	// Clock for timing 'gameloop'
	sf::Clock clock;

	// Get renderer instance
	renderer* renderer_ = renderer::getInstance();

	while (renderer_->isWindowOpen()) {
		// Update renderer. Events, drawing, etc.
		renderer_->update(clock.getElapsedTime());

		// Sleep for rest of the 16ms left.
		sf::sleep(sf::milliseconds(16-clock.getElapsedTime().asMilliseconds()));
	}
	
	return EXIT_SUCCESS;

}