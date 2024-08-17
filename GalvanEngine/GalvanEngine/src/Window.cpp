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
