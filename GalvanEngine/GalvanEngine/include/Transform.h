#pragma once
#include "Prerequisites.h"
#include "Component.h"
#include "Window.h"

class 
Transform : public Component {
public:
	Transform() : position(0.0f, 0.0f), 
                rotation(0.0f, 0.0f), 
                scale(1.0f, 1.0f), 
                Component(ComponentType::TRANSFORM) {}

	virtual 
	~Transform() = default;

	/**
   * @brief Actualiza el componente de malla.
   * @param deltaTime El tiempo transcurrido desde la última actualización.
   */
  void 
  update(float deltaTime) override {}

  /**
   * @brief Renderiza el componente de malla.
   * @param deviceContext Contexto del dispositivo para operaciones gráficas.
   */
  void 
  render(Window window) override {}

  void
  destroy() {};

  void
  Seek(const sf::Vector2f& targetPosition,
       float speed,
       float deltaTime,
       float range) {
    sf::Vector2f direction = targetPosition - position;
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (length > range) {
      direction /= length;  // Normaliza el vector
      position += direction * speed * deltaTime;
    }
  }

  void
  setPosition(const sf::Vector2f& _position) {
    position = _position;
  }
  
  void
  setRotation(const sf::Vector2f& _rotation) {
    rotation = _rotation;
  }
  
  void
  setScale(const sf::Vector2f& _scale) {
    scale = _scale;
  }

  sf::Vector2f& 
  getPosition() {
    return position;
  }
  
  sf::Vector2f&
  getRotation() {
    return rotation;
  }

  sf::Vector2f& 
  getScale() {
    return scale;
  }
private:
  sf::Vector2f position;  // Posición del objeto
  sf::Vector2f rotation;  // Rotación del objeto
  sf::Vector2f scale;     // Escala del objeto
};