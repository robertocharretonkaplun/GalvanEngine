#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Encapsula una ventana en una aplicaci�n gr�fica utilizando SFML.
 *
 * Esta clase proporciona funcionalidades b�sicas de gesti�n de ventanas,
 * como manejar eventos, limpiar, mostrar contenido y dibujar objetos.
 */
class 
Window {
public:
	/**
	 * @brief Constructor que inicializa la ventana con el tama�o y t�tulo especificados.
	 *
	 * @param width Ancho de la ventana en p�xeles.
	 * @param height Alto de la ventana en p�xeles.
	 * @param title T�tulo de la ventana como una cadena de texto.
	 */
	Window(int width, int height, const std::string& title);

	/**
	 * @brief Destructor que maneja la limpieza necesaria.
	 */
	~Window();

	/**
	 * @brief Maneja los eventos de la ventana, como la entrada de usuario y cambios en el estado de la ventana.
	 */
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
	 * @return true si la ventana est� abierta, false en caso contrario.
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

private:
	/**
	 * @brief Puntero al objeto interno SFML RenderWindow.
	 */
	sf::RenderWindow* m_window;
};
