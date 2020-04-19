#pragma once
#include <SFML/Graphics.hpp>
/*
	Class for every collidable in the game
*/
class Collidable
{
public:
	Collidable(float width, float height);

	sf::FloatRect getCollisionBox();
	bool isColliding(Collidable& object);

	virtual void onCollision(Collidable& object) = 0;
	virtual const sf::Vector2f& getSpritePosition() = 0;

private:
	sf::Vector2f spriteSize;
};
