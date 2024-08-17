#pragma once
#include "Prerequisites.h"

class 
SteeringBehaviors {
public:
	SteeringBehaviors() = default;
	~SteeringBehaviors() = default;

	/**
	 * @brief Mueve un objeto `sf::CircleShape` hacia una posici�n objetivo utilizando el efecto "Seek", deteni�ndose si entra dentro de un rango.
	 *
	 * @param shape El `sf::CircleShape` que se va a mover.
	 * @param targetPosition La posici�n objetivo hacia la cual el c�rculo se mover�.
	 * @param speed La velocidad a la que el c�rculo se mover�.
	 * @param deltaTime El tiempo transcurrido desde el �ltimo fotograma, utilizado para ajustar la velocidad del movimiento.
	 * @param range El rango dentro del cual el c�rculo se detendr�.
	 */
	void 
	Seek(sf::CircleShape& shape, 
			 const sf::Vector2f& targetPosition, 
			 float speed, 
			 float deltaTime, 
			 float range);

/**
 * @brief Mueve un objeto `sf::CircleShape` alej�ndolo de una posici�n objetivo utilizando el efecto "Flee" dentro de un rango.
 *
 * @param shape El `sf::CircleShape` que se va a mover.
 * @param targetPosition La posici�n desde la cual el c�rculo se alejar�.
 * @param speed La velocidad a la que el c�rculo se mover�.
 * @param deltaTime El tiempo transcurrido desde el �ltimo fotograma, utilizado para ajustar la velocidad del movimiento.
 * @param range El rango m�ximo dentro del cual el c�rculo se alejar� del objetivo.
 */
	void 
	Flee(sf::CircleShape& shape,
			 const sf::Vector2f& targetPosition, 
			 float speed,
			 float deltaTime, 
			 float range);

/**
 * @brief Mueve un objeto `sf::CircleShape` hacia una posici�n objetivo mientras evita obst�culos.
 *
 * @param shape El `sf::CircleShape` que se va a mover.
 * @param targetPosition La posici�n objetivo hacia la cual el c�rculo se mover�.
 * @param obstacle La forma del obst�culo a evitar.
 * @param speed La velocidad a la que el c�rculo se mover�.
 * @param deltaTime El tiempo transcurrido desde el �ltimo fotograma, utilizado para ajustar la velocidad del movimiento.
 * @param avoidDistance La distancia m�nima que el c�rculo debe mantener respecto al obst�culo.
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