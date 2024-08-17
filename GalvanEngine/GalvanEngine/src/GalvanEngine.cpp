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
#include "Prerequisites.h"
#include "Window.h"

int main() {
  Window window(800, 600, "Mi ventana SFML");

  sf::CircleShape shape(10.f);  // Radio de 50
  sf::CircleShape shape2(10.f);  // Radio de 50
  shape.setFillColor(sf::Color::Green);
  shape.setPosition(400.f, 300.f);  // Posición inicial en el centro
  shape2.setPosition(400.f, 300.f);  // Posición inicial en el centro

  sf::RectangleShape obstacle(sf::Vector2f(100.f, 200.f));  // Obstáculo rectangular
  obstacle.setFillColor(sf::Color::Red);
  obstacle.setPosition(600.f, 200.f);  // Posición del obstáculo

  float speed = 200.f;  // Velocidad del movimiento

  sf::Clock clock;

  while (window.isOpen()) {
    window.handleEvents();

    sf::Time deltaTime = clock.restart();

    // Obtener la posición actual del mouse
    sf::Vector2i mousePosition = sf::Mouse::getPosition(*window.getWindow());
    sf::Vector2f mousePosF(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    // Llamar a la función Seek para mover el círculo hacia el mouse
    //Seek(shape, mousePosF, speed, deltaTime.asSeconds(), 50);

    // Llamar a la función Flee para alejar el círculo del mouse
    //Flee(shape, shape2.getPosition(), speed, deltaTime.asSeconds(), 25);

    // Llamar a ObstacleAvoidance para mover el círculo hacia el mouse evitando el obstáculo
    //ObstacleAvoidance(shape, mousePosF, obstacle, speed, deltaTime.asSeconds(), 1);


    window.clear();
    window.draw(shape);
    window.draw(shape2);
    window.draw(obstacle);

    window.display();
  }

  return 0;
}
