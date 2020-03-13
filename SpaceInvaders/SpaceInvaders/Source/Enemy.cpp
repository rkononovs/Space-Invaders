#include "../Include/Enemy.h"

Enemy::Enemy(sf::Vector2f startingPosition, Type type) : Collidable(enemyWidth, enemyHeight), newPosition(startingPosition), enemyType(type), startingPosition(startingPosition)
{
}

void Enemy::drawEnemy(sf::RenderWindow& window)
{
	sf::RectangleShape enemy;
	enemy.setSize(sf::Vector2f(enemyWidth, enemyHeight));
	enemy.setPosition(newPosition);
	enemy.setFillColor(sf::Color::Red);
	window.draw(enemy);
}

void Enemy::moveEnemy(float x, float y)
{
	newPosition += {x, y};
}

void Enemy::onCollision(Collidable& object)
{
	isEnemyAlive = false;
}

const sf::Vector2f& Enemy::getSpritePosition()
{
	return newPosition;
}

bool Enemy::isAlive()
{
	return isEnemyAlive;
}

void Enemy::revive()
{
	isEnemyAlive = true;
}

Enemy::Type Enemy::getType()
{
	return enemyType;
}
