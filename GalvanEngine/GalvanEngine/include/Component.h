#pragma once
class Window;

/**
 * @enum ComponentType
 * @brief Tipos de componentes disponibles en el juego.
 */
enum 
ComponentType {
	NONE = 0, 
	TRANSFORM = 1,
	SPRITE = 2,
	RENDERER = 3,
	PHYSICS = 4,
	AUDIOSOURCE = 5,
	SHAPE = 6,
};

/**
 * @class Component
 * @brief Clase base abstracta para todos los componentes del juego.
 *
 * La clase Component define la interfaz básica que todos los componentes deben implementar,
 * permitiendo actualizar y renderizar el componente, así como obtener su tipo.
 */
class 
Component {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	Component() = default;

	/**
	 * @brief Constructor con tipo de componente.
	 * @param type Tipo del componente.
	 */
	Component(const ComponentType type) : m_type(type) {}

	/**
	 * @brief Destructor virtual.
	 */
	virtual
	~Component() = default;

	/**
	 * @brief Método virtual puro para actualizar el componente.
	 * @param deltaTime El tiempo transcurrido desde la última actualización.
	 */
	virtual void
	update(float deltaTime) = 0;

	/**
	 * @brief Método virtual puro para renderizar el componente.
	 * @param Window Contexto del dispositivo para operaciones gráficas.
	 */
	virtual void
	render(Window window) = 0;

	/**
   * @brief Obtiene el tipo del componente.
   * @return El tipo del componente.
   */
  ComponentType 
  getType() const { return m_type; }

protected:
	ComponentType m_type; // Tipo de Componente.
};