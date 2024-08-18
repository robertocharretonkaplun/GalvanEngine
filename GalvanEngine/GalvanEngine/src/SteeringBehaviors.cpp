#include "SteeringBehaviors.h"

void 
SteeringBehaviors::Seek(sf::CircleShape& shape, 
												const sf::Vector2f& targetPosition, 
												float speed, 
												float deltaTime, 
												float range) {
	// Obtener la posición actual del círculo
	sf::Vector2f shapePosition = shape.getPosition();

	// Calcular la dirección desde el círculo hacia el objetivo
	sf::Vector2f direction = targetPosition - shapePosition;

	// Calcular la distancia al objetivo
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Si la distancia es mayor que el rango, mover el círculo hacia el objetivo
	if (length > range) {
		direction /= length;  // Normalizar la dirección
		shape.move(direction * speed * deltaTime);
	}
	// Si está dentro del rango, no hacer nada (el círculo se detiene)
}

void 
SteeringBehaviors::Flee(sf::CircleShape& shape, 
												const sf::Vector2f& targetPosition, 
												float speed, 
												float deltaTime, 
												float range) {
	// Obtener la posición actual del círculo
	sf::Vector2f shapePosition = shape.getPosition();

	// Calcular la dirección opuesta desde el círculo hacia el objetivo
	sf::Vector2f direction = shapePosition - targetPosition;

	// Calcular la distancia al objetivo
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Si la distancia está dentro del rango especificado, realizar el movimiento
	if (length < range && length != 0) {
		direction /= length;  // Normalizar la dirección
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
	// Obtener la posición actual del círculo
	sf::Vector2f shapePosition = shape.getPosition();

	// Calcular la dirección desde el círculo hacia el objetivo
	sf::Vector2f direction = targetPosition - shapePosition;

	// Calcular la distancia al objetivo
	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

	// Normalizar la dirección
	if (length != 0) {
		direction /= length;
	}

	// Detectar si el círculo está cerca del obstáculo
	sf::FloatRect obstacleBounds = obstacle.getGlobalBounds();
	if (obstacleBounds.intersects(sf::FloatRect(shapePosition.x, shapePosition.y, shape.getRadius() * 2, shape.getRadius() * 2))) {
		// Calcular una nueva dirección para evitar el obstáculo
		sf::Vector2f obstaclePosition = obstacle.getPosition();
		sf::Vector2f avoidanceDirection = shapePosition - obstaclePosition;

		// Normalizar la dirección de evitación
		float avoidanceLength = std::sqrt(avoidanceDirection.x * avoidanceDirection.x + avoidanceDirection.y * avoidanceDirection.y);
		if (avoidanceLength != 0) {
			avoidanceDirection /= avoidanceLength;
		}

		// Ajustar la dirección final combinando la dirección original y la de evitación
		direction += avoidanceDirection * avoidDistance;
	}

	// Mover el círculo en la dirección final calculada
	shape.move(direction * speed * deltaTime);
}
