#include "BaseApp.h"

bool
BaseApp::init() {
	// Init window
	m_window = new Window(800, 600, "Mi ventana SFML");

	// Init Objects
	shape.setRadius(10.0f);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(400.f, 300.f);  // Posición inicial en el centro
	shape2.setRadius(10.0f);
	shape2.setPosition(400.f, 300.f);  // Posición inicial en el centro

	obstacle.setSize(sf::Vector2f( 100.0f, 100.0f));
	obstacle.setFillColor(sf::Color::Red);
	obstacle.setPosition(600.f, 200.f);  // Posición del obstáculo

	float speed = 200.f;  // Velocidad del movimiento

	return false;
}

void 
BaseApp::update() {
	// Obtener la posición actual del mouse
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

	// Llamar a la función Seek para mover el círculo hacia el mouse
	//Seek(shape, mousePosF, speed, deltaTime.asSeconds(), 50);

	// Llamar a la función Flee para alejar el círculo del mouse
	//Flee(shape, shape2.getPosition(), speed, deltaTime.asSeconds(), 25);

	// Llamar a ObstacleAvoidance para mover el círculo hacia el mouse evitando el obstáculo
	//ObstacleAvoidance(shape, mousePosF, obstacle, speed, deltaTime.asSeconds(), 1);
}

void 
BaseApp::render() {
		m_window->clear();
		m_window->draw(shape);
		m_window->draw(shape2);
		m_window->draw(obstacle);

		m_window->display();
}

void 
BaseApp::destroy() {
	delete m_window;
}

int 
BaseApp::run() {
	init();
	while (m_window->isOpen()) {
		m_window->handleEvents();

		sf::Time deltaTime = clock.restart();

		update();
		render();
	}

	destroy();
	return 0;
}
