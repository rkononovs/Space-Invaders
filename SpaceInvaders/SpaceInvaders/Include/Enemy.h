#pragma once
#include <SFML/Graphics.hpp>
/*
	Class for single enemy
*/


class Enemy
{
public:
	enum class Type // enum for different looking enemies
	{
		Crab, Octopus, Squid
	};
	Enemy(sf::Vector2f startingPosition, Type type);
	void drawEnemy(sf::RenderWindow& window);
	void moveEnemy(float x, float y);
	sf::Vector2f& getPosition();

	bool isAlive();
	void revive();
	Type getType();
private:
	const sf::Vector2f startingPosition;
	sf::Vector2f newPosition;
	bool isEnemyAlive = false;
	Type enemyType;

};
