#include "Actor.h"
#include "Services\NotificationService.h"

Actor::Actor(std::string actorName) {
	NotificationService& notifier = NotificationService::getInstance();

	// Setup Actor Name
	m_name = actorName;

	// Setup Shape
	EngineUtilities::TSharedPointer<ShapeFactory> shape = EngineUtilities::MakeShared<ShapeFactory>();
	addComponent(shape);

	// Setup Transform
	EngineUtilities::TSharedPointer<Transform> transform = EngineUtilities::MakeShared<Transform>();
	addComponent(transform);

	// Setup Sprite

	// Notify that the actor was created correctly
	notifier.Log("Actor named " + m_name + " was created.");
}

void 
Actor::update(float deltaTime) {
	auto transform = getComponent<Transform>();
	auto shape = getComponent<ShapeFactory>();

	if (transform && shape) {
		shape->setPosition(transform->getPosition());
		shape->setRotation(transform->getRotation().x);
		shape->setScale(transform->getScale());
	}
}

void Actor::render(Window& window)
{
	for (unsigned int i = 0; i < components.size(); i++) {
		if (components[i].dynamic_pointer_cast<ShapeFactory>())	{
			window.draw(*components[i].dynamic_pointer_cast<ShapeFactory>()->getShape());
		}
	}
}

void Actor::destroy()
{
}
