#include "Actor.h"

Actor::Actor(std::string actorName) {
	// Setup Actor Name
	m_name = actorName;

	// Setup Shape
	EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();
	addComponent(shape);

	// Setup Transform

	// Setup Sprite
}

void Actor::update(float deltaTime)
{
}

void Actor::render(Window& window)
{
	for (unsigned int i = 0; i < components.size(); i++) {
		window.draw(*components[i].dynamic_pointer_cast<ShapeFactory>()->getShape());
	}
}

void Actor::destroy()
{
}
