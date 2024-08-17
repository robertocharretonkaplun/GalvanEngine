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
#include "Window.h"

Window::Window(int width, int height, const std::string& title) {
	m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	if (!m_window) {
		ERROR("Window", "Window", "CHECK FOR CREATION METHOD");
	}
	else {
		MESSAGE("Window", "Window", "OK");
	}
}

Window::~Window() {
	//SAFE_PTR_RELEASE(m_window);
	delete m_window;
}

void 
Window::handleEvents() {
	sf::Event event;
	while (m_window->pollEvent(event)) {
		if (event.type == sf::Event::Closed)
		{
			m_window->close();
		}
		// Manejar el evento de redimensionar
		if (event.type == sf::Event::Resized) {
			// Obtener el nuevo tamaño de la ventana
			unsigned int newWidth = event.size.width;
			unsigned int newHeight = event.size.height;

			// Aquí puedes hacer lo que necesites con el nuevo tamaño
			// Por ejemplo, podrías ajustar los límites del dibujo o cualquier otro elemento

			// Opcional: Redefinir el tamaño de la vista para ajustarse al nuevo tamaño de la ventana
			sf::View view = m_window->getView();
			view.setSize(static_cast<float>(newWidth), static_cast<float>(newHeight));
			m_window->setView(view);
		}
	}
}

void 
Window::clear() {
	m_window->clear();
}

void 
Window::display() {
	m_window->display();
}

bool 
Window::isOpen() const {
	return m_window->isOpen();
}

void 
Window::draw(const sf::Drawable& drawable) {
	m_window->draw(drawable);
}

sf::RenderWindow* 
Window::getWindow() {
	return m_window;
}
