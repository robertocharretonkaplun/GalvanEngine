#pragma once
#include "Prerequisites.h"

class 
SteeringBehaviors {
public:
	SteeringBehaviors() = default;
	~SteeringBehaviors() = default;

	/**
	 * @brief Mueve un objeto `sf::CircleShape` hacia una posición objetivo utilizando el efecto "Seek", deteniéndose si entra dentro de un rango.
	 *
	 * @param shape El `sf::CircleShape` que se va a mover.
	 * @param targetPosition La posición objetivo hacia la cual el círculo se moverá.
	 * @param speed La velocidad a la que el círculo se moverá.
	 * @param deltaTime El tiempo transcurrido desde el último fotograma, utilizado para ajustar la velocidad del movimiento.
	 * @param range El rango dentro del cual el círculo se detendrá.
	 */
	void 
	Seek(sf::CircleShape& shape, 
			 const sf::Vector2f& targetPosition, 
			 float speed, 
			 float deltaTime, 
			 float range);

/**
 * @brief Mueve un objeto `sf::CircleShape` alejándolo de una posición objetivo utilizando el efecto "Flee" dentro de un rango.
 *
 * @param shape El `sf::CircleShape` que se va a mover.
 * @param targetPosition La posición desde la cual el círculo se alejará.
 * @param speed La velocidad a la que el círculo se moverá.
 * @param deltaTime El tiempo transcurrido desde el último fotograma, utilizado para ajustar la velocidad del movimiento.
 * @param range El rango máximo dentro del cual el círculo se alejará del objetivo.
 */
	void 
	Flee(sf::CircleShape& shape,
			 const sf::Vector2f& targetPosition, 
			 float speed,
			 float deltaTime, 
			 float range);

/**
 * @brief Mueve un objeto `sf::CircleShape` hacia una posición objetivo mientras evita obstáculos.
 *
 * @param shape El `sf::CircleShape` que se va a mover.
 * @param targetPosition La posición objetivo hacia la cual el círculo se moverá.
 * @param obstacle La forma del obstáculo a evitar.
 * @param speed La velocidad a la que el círculo se moverá.
 * @param deltaTime El tiempo transcurrido desde el último fotograma, utilizado para ajustar la velocidad del movimiento.
 * @param avoidDistance La distancia mínima que el círculo debe mantener respecto al obstáculo.
 */
	void 
	ObstacleAvoidance(sf::CircleShape& shape, 
										const sf::Vector2f& targetPosition, 
										const sf::RectangleShape& obstacle, 
										float speed, 
										float deltaTime, 
										float avoidDistance);
private:

};