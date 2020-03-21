#pragma once

#include "../Include/Enemy.h"
#include "../Include/ScreenInfo.h"
#include "../Include/Bullet.h"

#include <vector>

class EnemyControler
{
public:

	EnemyControler();
	void moveEnemies();
	void drawEnemies(sf::RenderWindow& window);
	void destroyEnemy();
	bool checkBulletCollisions(std::vector<Bullet>& bullets);
	sf::Vector2f randomLowestEnemyPosition();
	std::vector<sf::Vector2f> bulletCollision(std::vector<Bullet>& bullets);

private:
	const int gapBetweenEnemies = 10;

	int row = 5;
	int column = 11;
	int aliveEnemies = row * column; // Maybe refracture
	int stepDown; // DEBUGING PURPOSES ! DELETE LATER !
	int steps; // DEBUGING PURPOSES ! DELETE LATER !

	bool moveDown = false;
	bool moveLeft = false;

	float moveSpeed;

	sf::Clock moveTimer;
	sf::Time moveTimeGap;
	std::vector<Enemy> enemies;
};