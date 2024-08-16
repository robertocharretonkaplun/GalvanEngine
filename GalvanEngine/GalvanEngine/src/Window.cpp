#include "Window.h"

Window::Window(int width, int height, const std::string& title) {
	m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);
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
			m_window->close();
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
