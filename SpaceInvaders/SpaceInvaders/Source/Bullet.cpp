#include "../Include/Bullet.h"

Bullet::Bullet(sf::Vector2f& position, Direction direction) : bulletPosition(position), bulletDirection(direction)
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
}

void Bullet::onCollide()
{
	destroy();
}

void Bullet::updateBullet()
{
	float speed = bulletSpeed * (float)bulletDirection;
	bulletPosition.y += speed;
}

bool Bullet::isBulletActive() {
	return isActive;
}
