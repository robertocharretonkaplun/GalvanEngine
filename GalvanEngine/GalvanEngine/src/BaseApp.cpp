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
#include "Services\NotificationService.h"
#include "Services\ResourceManager.h"

BaseApp::~BaseApp()
{
	NotificationService& notifier = NotificationService::getInstance();
	notifier.saveMessagesToFile("LogData.txt");
}

int
BaseApp::run() {
	NotificationService& notifier = NotificationService::getInstance();

	if (!initialize()) {
		notifier.addMessage(ConsolErrorType::ERROR, "Initializes result on a false statemente, check method validations");
		notifier.saveMessagesToFile("LogData.txt");
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	else {
		notifier.addMessage(ConsolErrorType::INFO, "All programs were initialized correctly");
	}
	m_GUI.init();

	while (m_window->isOpen()) {
		m_window->handleEvents();
		update();
		render();
	}

	cleanup();
	return 0;
}

bool
BaseApp::initialize() {
	NotificationService& notifier = NotificationService::getInstance();
	m_window = new Window(1920, 1080, "Galvan Engine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}
	// Track Actor
	Track = EngineUtilities::MakeShared<Actor>("Track");
	if (!Track.isNull()) {
		Track->getComponent<ShapeFactory>()->createShape(ShapeType::RECTANGLE);

		// Establecer posición, rotación y escala desde Transform
		Track->getComponent<Transform>()->setPosition(sf::Vector2f(0.0f, 0.0f));
		Track->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
		Track->getComponent<Transform>()->setScale(sf::Vector2f(11.0f, 12.0f));

		// Obtener el Resource Manager
		ResourceManager& resourceMan = ResourceManager::getInstance();

		// Cargar la textura para el actor Track
		if (!resourceMan.loadTexture("Track", "png")) {
			notifier.addMessage(ConsolErrorType::ERROR, "Cant load texture");
		}

		// Obtenemos la textura Carga
		EngineUtilities::TSharedPointer<Texture> trackTexture = resourceMan.getTexture("Track");
		if (trackTexture) {
			Track->getComponent<ShapeFactory>()->getShape()->setTexture(&trackTexture->getTexture());
		}

		// Almacenamos el actor
		m_actors.push_back(Track);
	}
	// Triangle Actor
	Circle = EngineUtilities::MakeShared<Actor>("Circle");
	if (!Circle.isNull()) {
		Circle->getComponent<ShapeFactory>()->createShape(ShapeType::CIRCLE);

		// Establecer posición, rotación y escala desde Transform
		Circle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
		Circle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
		Circle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));

		if (!Luigi.loadFromFile("Characters/tile000.png")) {
			std::cout << "Error de carga de textura" << std::endl;
			return -1; // Manejar error de carga
		}
		Circle->getComponent<ShapeFactory>()->getShape()->setTexture(&Luigi);
	}
	m_actors.push_back(Circle);

	// Triangle Actor
	Triangle = EngineUtilities::MakeShared<Actor>("Triangle");
	if (!Triangle.isNull()) {
		Triangle->getComponent<ShapeFactory>()->createShape(ShapeType::TRIANGLE);
		Triangle->getComponent<Transform>()->setPosition(sf::Vector2f(200.0f, 200.0f));
		Triangle->getComponent<Transform>()->setRotation(sf::Vector2f(0.0f, 0.0f));
		Triangle->getComponent<Transform>()->setScale(sf::Vector2f(1.0f, 1.0f));
	}

	m_actors.push_back(Triangle);

	return true;
}

void
BaseApp::update() {
	// Update window method
	m_window->update();

	// Mouse Position
	sf::Vector2i mousePosition = sf::Mouse::getPosition(*m_window->getWindow());
	sf::Vector2f mousePosF(static_cast<float>(mousePosition.x),
		static_cast<float>(mousePosition.y));

	// Update the actors
	for (auto& actor : m_actors) {
		if (!actor.isNull()) {
			actor->update(m_window->deltaTime.asSeconds());
			if (actor->getName() == "Circle") {
				updateMovement(m_window->deltaTime.asSeconds(), actor);
			}
		}
	}
}

void
BaseApp::render() {
	NotificationService& notifier = NotificationService::getInstance();

	m_window->clear();

	// Render the actors
	for (auto& actor : m_actors) {
		if (!actor.isNull()) {
			actor->render(*m_window);
		}
	}

	// Mostrar el render en ImGui
	m_window->renderToTexture();  // Finaliza el render a la textura
	m_window->showInImGui();      // Muestra la textura en ImGui
	m_GUI.barMenu();
	m_GUI.Outliner(m_actors);
	m_GUI.console(notifier.getNotifications());
	m_GUI.inspector(m_actors);
	m_window->render();
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
	if (!circle || circle.isNull()) {
		return;
	}

	// Obtener el componente Transform
	auto transform = circle->getComponent<Transform>();
	if (transform.isNull()) {
		return;
	}

	// Posición actual del destino (punto de recorrido)
	sf::Vector2f targetPos = waypoints[currentWaypoint];

	// Llamar al Seek del Transform
	transform->Seek(targetPos, 200.0f, deltaTime, 10.0f);

	// Obtener la posición actual del actor desde Transform
	sf::Vector2f currentPos = transform->getPosition();

	// Comprobar si el actor ha alcanzado el destino (o está cerca)
	float distanceToTarget = std::sqrt(std::pow(targetPos.x - currentPos.x, 2) + std::pow(targetPos.y - currentPos.y, 2));

	if (distanceToTarget < 10.0f) { // Umbral para considerar que ha llegado
		currentWaypoint = (currentWaypoint + 1) % waypoints.size(); // Ciclar a través de los puntos
	}
}
