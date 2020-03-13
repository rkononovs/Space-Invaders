#include "../Include/Collidable.h"

Collidable::Collidable(float width, float height) : spriteSize(width, height)
{
}

sf::FloatRect Collidable::getCollisionBox()
{
	return
	{
		getSpritePosition().x,
		getSpritePosition().y,
		spriteSize.x, // Width
		spriteSize.y // Height
	};
}

bool Collidable::isColliding(Collidable& object)
{
	if (getCollisionBox().intersects(object.getCollisionBox())) {
		isColliding(object);
		return true;
	}
	return false;
}
