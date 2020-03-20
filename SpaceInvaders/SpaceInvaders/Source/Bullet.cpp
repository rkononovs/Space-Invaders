#include "../Include/Bullet.h"

#include <iostream> // FOR TESTING PURPOSES

Bullet::Bullet(sf::Vector2f& position, Direction direction) : Collidable(bulletWidth, bulletHeight), bulletPosition(position), bulletDirection(direction)
{
}

void Bullet::drawBullet(sf::RenderWindow& window)
{
	sf::RectangleShape bullet;
	bullet.setSize(sf::Vector2f(bulletWidth, bulletHeight));
	bullet.setPosition(bulletPosition);
	bullet.setFillColor(sf::Color::Red);
	window.draw(bullet);
}

void Bullet::destroy()
{
	isActive = false;
	std::cout << "Bullet is destroyed" << std::endl; // FOR TESTING PURPOSES
}

void Bullet::onCollision(Collidable& object)
{
	destroy();
}

void Bullet::updateBullet()
{
	float speed = bulletSpeed * (float)bulletDirection;
	bulletPosition.y += speed;
	if (bulletPosition.y <= 0) {
		destroy();
	}
}

bool Bullet::isBulletActive() {
	return isActive;
}

const sf::Vector2f& Bullet::getSpritePosition()
{
	return bulletPosition;
}
