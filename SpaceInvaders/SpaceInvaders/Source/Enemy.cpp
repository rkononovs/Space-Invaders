#include "../Include/Enemy.h"

Enemy::Enemy(sf::Vector2f startingPosition, Type type) : newPosition(startingPosition), enemyType(type), startingPosition(startingPosition)
{
}

void Enemy::drawEnemy(sf::RenderWindow& window)
{
	sf::RectangleShape enemy;
	enemy.setSize(sf::Vector2f(30.0f, 30.0f));
	enemy.setPosition(newPosition);
	enemy.setFillColor(sf::Color::Red);
	window.draw(enemy);
}

void Enemy::moveEnemy(float x, float y)
{
	newPosition += {x, y};
}

sf::Vector2f& Enemy::getPosition()
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
