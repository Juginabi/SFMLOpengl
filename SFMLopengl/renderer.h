#include "SFML/Window.hpp"
#include "SFML/OpenGL.hpp"

class renderer {
	// Render window
	sf::Window window_;

	// Event system
	sf::Event event_;

	// Instance of this class. Singleton.
	static renderer* renderer_;

	// Last frametime when update was called
	sf::Time lastUpdateTime_;

	// This will identify our vertex buffer
	GLuint vertexbuffer;

	// This is just for testing shaders
	GLuint programID_;

protected:
	// Protected constructor because singleton
	renderer() : lastUpdateTime_(sf::milliseconds(0)) {};

	// Protected copy constructor because singleton
	renderer(renderer&);

	// Protected destructor
	~renderer();

	// initializer for sfml and glew init.
	void initialize();

public:
	// Public interface to get instance of this class
	static renderer* getInstance();

	// Interface for sfml window.isOpen()
	bool isWindowOpen();

	// Update function with frametime parameter.
	void update(sf::Time);
};