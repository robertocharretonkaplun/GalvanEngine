#pragma once
#include "Prerequisites.h"

class 
Window {
public:
	Window() = default;
	Window(int width, int height, const std::string& title);
	~Window();

	void
	handleEvents();

	/**
	 * @brief Limpia el contenido de la ventana con el color predeterminado.
	 */
	void 
	clear();

	/**
	 * @brief Muestra el contenido de la ventana en la pantalla.
	 */
	void 
	display();

	/**
	 * @brief Verifica si la ventana sigue abierta.
	 *
	 * @return true si la ventana está abierta, false en caso contrario.
	 */
	bool 
	isOpen() const;

	/**
	 * @brief Dibuja un objeto que puede ser dibujado en la ventana.
	 *
	 * @param drawable Referencia a un objeto SFML que puede ser dibujado.
	 */
	void 
	draw(const sf::Drawable& drawable);

	/**
	 * @brief Obtiene el objeto interno SFML RenderWindow.
	 *
	 * @return Un puntero al objeto interno SFML RenderWindow.
	 */
	sf::RenderWindow* 
	getWindow();

	// Funcion de inicializacion
	void
	init();

	// Funcion que se actualiza por frame
	void
	update();

	// Funcion de renderizado
	void
	render();

	void
	destroy();

private:
	sf::RenderWindow* m_window;
};