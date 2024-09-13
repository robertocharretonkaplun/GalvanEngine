#pragma once
#include "Prerequisites.h"

class 
ShapeFactory {
public:
	ShapeFactory() = default;
	~ShapeFactory() = default;

	sf::Shape* 
	createShape(ShapeType shapeType);
private:

};