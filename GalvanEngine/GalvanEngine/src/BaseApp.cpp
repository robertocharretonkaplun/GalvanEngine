/*
 * MIT License
 *
 * Copyright (c) 2024 Roberto Charreton
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * In addition, any project or software that uses this library or class must include
 * the following acknowledgment in the credits:
 *
 * "This project uses software developed by Roberto Charreton and Attribute Overload."
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/
#include "BaseApp.h"

int
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		deltaTime = clock.restart();
		update();
		render();
	}

	cleanup();
	return 0;
}

bool
BaseApp::initialize() {
	m_window = new Window(800, 600, "Galvan Engine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}

	// Triangle Actor
	Circle = EngineUtilities::MakeShared<Actor>("Circle");
	if (!Circle.isNull()) {
		Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);
		Circle->getComponent<ShapeFactory>()->setPosition(200.0f, 200.0f);
		Circle->getComponent<ShapeFactory>()->setFillColor(sf::Color::Blue);
	}

	// Triangle Actor
	Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
	if (!Triangle.isNull()) {
		Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
	}

	return true;
}

void
BaseApp::update() {
	// Mouse Position
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
		static_cast<float>(mousePosition.y));

	if (!Circle.isNull()) {
		/*Circle->getComponent<ShapeFactory>()->Seek(mousePosF,
																							 200.0f,
																							 deltaTime.asSeconds(),
																							 10.0f);*/
		updateMovement(deltaTime.asSeconds(), Circle);
	}

}

void
BaseApp::render() {
	m_window->clear();
	Circle->render(*m_window);
	Triangle->render(*m_window);
	m_window->display();
}

void
BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
}

void
BaseApp::updateMovement(float deltaTime, EngineUtilities::TSharedPointer<Actor> circle) {
	// Verificar si el Circle es nulo
	if (!circle || circle.isNull()) return;

	// Posición actual del destino (punto de recorrido)
	sf::Vector2f targetPos = waypoints[currentWaypoint];

	// Llamar al Seek hacia el punto de recorrido actual
	circle->getComponent<ShapeFactory>()->Seek(targetPos, 200.0f, deltaTime, 10.0f);

	// Obtener la posición actual del actor
	sf::Vector2f currentPos = circle->getComponent<ShapeFactory>()->getShape()->getPosition();

	// Comprobar si el actor ha alcanzado el destino (o está cerca)
	float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

	if (distanceToTarget < 10.0f) { // Umbral para considerar que ha llegado
		// Pasar al siguiente waypoint
		currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a través de los puntos
	}
}
