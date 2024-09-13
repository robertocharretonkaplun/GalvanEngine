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
#include "BaseApp.h"

int 
BaseApp::run() {
	if (!initialize()) {
		ERROR("BaseApp", "run", "Initializes result on a false statemente, check method validations");
	}
	while (m_window->isOpen()) {
		m_window->handleEvents();
		update();
		render();
	}

	cleanup();
	return 0;
}

bool
BaseApp::initialize() {
	m_window = new Window(800, 600, "Galvan Engine");
	if (!m_window) {
		ERROR("BaseApp", "initialize", "Error on window creation, var is null");
		return false;
	}
	shape = new sf::CircleShape(10.0f);
	
	if (!shape) {
		ERROR("BaseApp", "initialize", "Error on shape creation, var is null");
		return false;
	}
	
	shape->setFillColor(sf::Color::Blue);
	shape->setPosition(200.0f, 200.0f);

	Triangulo = m_shapeFactory.createShape(ShapeType::TRIANGLE);
	if (!Triangulo) {
		ERROR("BaseApp", "initialize", "Error on triangulo creation, var is null");
		return false;
	}

	return true;
}

void 
BaseApp::update() {
}

void 
BaseApp::render() {
	m_window->clear();
	m_window->draw(*shape);
	m_window->draw(*Triangulo);
	m_window->display();
}

void 
BaseApp::cleanup() {
	m_window->destroy();
	delete m_window;
	delete shape;
	delete Triangulo;
}
