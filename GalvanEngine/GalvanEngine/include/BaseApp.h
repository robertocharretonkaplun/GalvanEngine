#pragma once
#include "Prerequisites.h"
#include "Window.h"

class 
BaseApp {
public:
	BaseApp() = default;
	~BaseApp() = default;

	bool
	init();

	void
	update();

	void
	render();

	void
	destroy();

	int
	run();

private:
	Window* m_window;
	sf::Clock clock;

	sf::CircleShape shape;  // Radio de 50
	sf::CircleShape shape2;  // Radio de 50
	sf::RectangleShape obstacle;  // Obstáculo rectangular
};
