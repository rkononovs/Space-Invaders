#pragma once
#include <SFML/Graphics.hpp>

#include "../Include/Collidable.h"
/*
	Class for single enemy
*/
class Enemy : public Collidable
{
public:
	enum class Type // enum for different looking enemies
	{
		Crab, Octopus, Squid
	};
	Enemy(sf::Vector2f startingPosition, Type type);
	void drawEnemy(sf::RenderWindow& window);
	void moveEnemy(float x, float y);
	void onCollision(Collidable& object);
	void revive();
	bool isAlive();

	sf::FloatRect getCollisionBox();
	Type getType();

	const sf::Vector2f& getSpritePosition();

	constexpr static float enemyWidth = 30.0f;
	constexpr static float enemyHeight = 30.0f;


private:
	bool isEnemyAlive = true;

	sf::Vector2f newPosition;
	Type enemyType;

	sf::Vector2f startingPosition;
};
