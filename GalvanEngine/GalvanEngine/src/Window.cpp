#include "Window.h"

Window::Window(int width, int height, const std::string& title) {
	m_window = new sf::RenderWindow(sf::VideoMode(width, height), title);

	if (!m_window) {
		ERROR("Window", "Window", "CHECK CONSTRUCTOR" );
	}
	else {
		MESSAGE("Window", "Window", "OK");
	}
}

Window::~Window() {
	delete m_window;
}

void
Window::handleEvents() {
	sf::Event event;
	while (m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_window->close();
	}
}

void
Window::clear() {
	if (m_window != nullptr) {
		m_window->clear();
	}
	else {
		ERROR("Window", "clear", "CHECK FOR WINDOW POINTER DATA" );
	}
}

void
Window::display() {
	if (m_window != nullptr) {
		m_window->display();
	}
	else {
		ERROR("Window", "display", "CHECK FOR WINDOW POINTER DATA" );
	}
}

bool
Window::isOpen() const {
	if (m_window != nullptr) {
		return m_window->isOpen();
	}
	else {
		ERROR("Window", "isOpen", "CHECK FOR WINDOW POINTER DATA" );
		return false;
	}
}

void
Window::draw(const sf::Drawable& drawable) {
	if (m_window != nullptr) {
		m_window->draw(drawable);
	}
	else {
		ERROR("Window", "draw", "CHECK FOR WINDOW POINTER DATA" );
	}
}

sf::RenderWindow*
Window::getWindow() {
	if (m_window != nullptr) {
		return m_window;
	}
	else {
		ERROR("Window", "getWindow", "CHECK FOR WINDOW POINTER DATA" );
		return nullptr;
	}
}

void 
Window::destroy() {
	SAFE_PTR_RELEASE(m_window);
}
