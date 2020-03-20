#pragma once
#include <SFML/Graphics.hpp>

#include "../Include/ScreenInfo.h"
#include "../Include/Collidable.h"
/*
	Class for single bullet
*/
class Bullet : public Collidable
{
public:
	enum class Direction {
		Down = 1,
		Up = -1
	};
	Bullet(sf::Vector2f& position, Direction direction);
	void drawBullet(sf::RenderWindow& window);
	void destroy();
	void onCollision(Collidable& object);
	void updateBullet();
	bool isBulletActive();

	const sf::Vector2f& getSpritePosition();

	constexpr static float bulletWidth = 3.0f;
	constexpr static float bulletHeight = 10.0f;
private:
	sf::Vector2f bulletPosition;
	Direction bulletDirection;
	float bulletSpeed = 10;
	bool isActive = true;


};