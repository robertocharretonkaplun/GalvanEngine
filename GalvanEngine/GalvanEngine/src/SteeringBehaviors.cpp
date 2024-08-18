#include "SteeringBehaviors.h"

void 
SteeringBehaviors::Seek(sf::CircleShape& shape, 
												const sf::Vector2f& targetPosition, 
												float speed, 
												float deltaTime, 
												float range) {
	// Obtener la posici�n actual del c�rculo
	sf::Vector2f shapePosition = shape.getPosition();

	// Calcular la direcci�n desde el c�rculo hacia el objetivo
	sf::Vector2f direction = targetPosition - shapePosition;

	// Calcular la distancia al objetivo
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Si la distancia es mayor que el rango, mover el c�rculo hacia el objetivo
	if (length > range) {
		direction /= length;  // Normalizar la direcci�n
		shape.move(direction * speed * deltaTime);
	}
	// Si est� dentro del rango, no hacer nada (el c�rculo se detiene)
}

void 
SteeringBehaviors::Flee(sf::CircleShape& shape, 
												const sf::Vector2f& targetPosition, 
												float speed, 
												float deltaTime, 
												float range) {
	// Obtener la posici�n actual del c�rculo
	sf::Vector2f shapePosition = shape.getPosition();

	// Calcular la direcci�n opuesta desde el c�rculo hacia el objetivo
	sf::Vector2f direction = shapePosition - targetPosition;

	// Calcular la distancia al objetivo
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Si la distancia est� dentro del rango especificado, realizar el movimiento
	if (length < range && length != 0) {
		direction /= length;  // Normalizar la direcci�n
		shape.move(direction * speed * deltaTime);
	}
}

void 
SteeringBehaviors::Arrive(sf::CircleShape& shape, 
													const sf::Vector2f& targetPosition, 
													float maxSpeed, 
													float slowRadius, 
													float deltaTime) {
	sf::Vector2f shapePosition = shape.getPosition();
	sf::Vector2f direction = targetPosition - shapePosition;
	float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	if (distance > 0) {
		float desiredSpeed = maxSpeed;
		if (distance < slowRadius) {
			desiredSpeed = maxSpeed * (distance / slowRadius);
		}

		sf::Vector2f desiredVelocity = (direction / distance) * desiredSpeed;
		shape.move(desiredVelocity * deltaTime);
	}
}

void 
SteeringBehaviors::ObstacleAvoidance(sf::CircleShape& shape, 
																		 const sf::Vector2f& targetPosition, 
																		 const sf::RectangleShape& obstacle, 
																		 float speed, 
																		 float deltaTime, 
																		 float avoidDistance) {
	// Obtener la posici�n actual del c�rculo
	sf::Vector2f shapePosition = shape.getPosition();

	// Calcular la direcci�n desde el c�rculo hacia el objetivo
	sf::Vector2f direction = targetPosition - shapePosition;

	// Calcular la distancia al objetivo
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Normalizar la direcci�n
	if (length != 0) {
		direction /= length;
	}

	// Detectar si el c�rculo est� cerca del obst�culo
	sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();
	if (obstacleBounds.intersects(sf::FloatRect(shapePosition.x, shapePosition.y, shape.getRadius() * 2, shape.getRadius() * 2))) {
		// Calcular una nueva direcci�n para evitar el obst�culo
		sf::Vector2f obstaclePosition = obstacle.getPosition();
		sf::Vector2f avoidanceDirection = shapePosition - obstaclePosition;

		// Normalizar la direcci�n de evitaci�n
		float avoidanceLength = std::sqrt(avoidanceDirection.x * avoidanceDirection.x + avoidanceDirection.y * avoidanceDirection.y);
		if (avoidanceLength != 0) {
			avoidanceDirection /= avoidanceLength;
		}

		// Ajustar la direcci�n final combinando la direcci�n original y la de evitaci�n
		direction += avoidanceDirection * avoidDistance;
	}

	// Mover el c�rculo en la direcci�n final calculada
	shape.move(direction * speed * deltaTime);
}
