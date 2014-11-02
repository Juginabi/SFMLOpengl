#include <iostream>
#include <GL\glew.h>
#include <SFML/OpenGL.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "common.h"
#include "renderer.h"
// #include "scene\gameObjectManager.h"
#include "scene/gameObject.h"
#include "scene/component.h"
#include "scene/components\gocTransform.h"
#include "scene/components\gocVisual.h"
#include "scene/components\gocVisualRectangle.h"

int main(int args, char* argv[]) {

	std::cout << "SFML and GLEW testing!" << std::endl;

	// Clock for timing 'gameloop'
	sf::Clock clock;
	sf::Time frameStart;
	sf::Time frameBudget = sf::milliseconds(16);

	// Get renderer instance
	renderer* renderer_ = renderer::getInstance();

	clock.restart();

	GameObject *obj = new GameObject("Rectangle");
	obj->attachComponent(new GocVisualRectangle());
	Component* comp = obj->getComponent("GocVisual");


	// Gameloop
	while (renderer_->isWindowOpen()) {
		frameStart = clock.getElapsedTime();
		// Update renderer. Events, drawing, etc.
		renderer_->update(frameStart);

		// Sleep for rest of the 16ms left.
		sf::Time sleepDuration = frameBudget - (frameStart - clock.getElapsedTime());
		//std::cout << "Sleeping for " << sleepDuration.asMilliseconds() << " - frameTime: " << frameStart.asMilliseconds() <<  std::endl;
		sf::sleep(sleepDuration);
	}

	std::cout << "Press any key to continue.";
	std::cin.get();
	
	return EXIT_SUCCESS;

}