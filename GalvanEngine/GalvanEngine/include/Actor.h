#pragma once
#include "Prerequisites.h"
#include "Entity.h"
#include "ShapeFactory.h"

class 
Actor : Entity {
public:
  /**
   * @brief Constructor por defecto.
   */
  Actor() = default;

  Actor(std::string actorName);

  /**
   * @brief Destructor virtual.
   */
  virtual 
  ~Actor() = default;

  /**
   * @brief Actualiza el actor.
   * @param deltaTime El tiempo transcurrido desde la última actualización.
   */
  void
  update(float deltaTime) override;

  /**
   * @brief Renderiza el actor.
   * @param window Contexto del dispositivo para operaciones gráficas.
   */
  void 
  render(Window& window) override;

  /**
   * @brief Destruye el actor y libera los recursos asociados.
   */
  void 
  destroy();

  /**
   * @brief Obtiene un componente específico del actor.
   * @tparam T Tipo del componente que se va a obtener.
   * @return Puntero compartido al componente, o nullptr si no se encuentra.
   */
  template <typename T>
  EngineUtilities::TSharedPointer<T> 
  getComponent();
private:
  std::string m_name = "Actor"; ///< Nombre del actor.
};

/**
 * El propósito de esta función es buscar y devolver un componente específico de un actor,
 * utilizando el tipo de componente especificado como argumento de la plantilla.
 * Si el componente no se encuentra, la función devuelve nullptr.
 */
template<typename T>
inline EngineUtilities::TSharedPointer<T>
Actor::getComponent() {
  for (auto& component : components) {
    EngineUtilities::TSharedPointer<T> specificComponent = component.template dynamic_pointer_cast<T>();
    if (specificComponent) {
      return specificComponent;
    }
  }
  // Devuelve un TSharedPointer vacío si no se encuentra el componente
  return EngineUtilities::TSharedPointer<T>();
}
