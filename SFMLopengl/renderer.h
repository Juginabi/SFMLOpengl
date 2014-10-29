#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"

class renderer {
	// Render window
	sf::Window window_;

	// Event system
	sf::Event event_;

	static renderer* renderer_;

	GLuint programID_;

protected:
	renderer() {};
	renderer(renderer&);
	void initialize();

public:
	static renderer* getInstance();

	bool isWindowOpen();

	void update(sf::Time);
};