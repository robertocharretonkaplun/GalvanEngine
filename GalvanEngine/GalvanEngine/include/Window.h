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
#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Encapsula una ventana en una aplicación gráfica utilizando SFML.
 *
 * Esta clase proporciona funcionalidades básicas de gestión de ventanas,
 * como manejar eventos, limpiar, mostrar contenido y dibujar objetos.
 */
class 
Window {
public:
	/**
	 * @brief Constructor que inicializa la ventana con el tamaño y título especificados.
	 *
	 * @param width Ancho de la ventana en píxeles.
	 * @param height Alto de la ventana en píxeles.
	 * @param title Título de la ventana como una cadena de texto.
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

private:
	/**
	 * @brief Puntero al objeto interno SFML RenderWindow.
	 */
	sf::RenderWindow* m_window;
};
