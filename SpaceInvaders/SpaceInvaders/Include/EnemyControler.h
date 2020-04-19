#pragma once
#include "../Include/Enemy.h"
#include "../Include/ScreenInfo.h"
#include "../Include/Bullet.h"
#include "../Include/Animator.h"
#include "../Include/ResourceManager.h"

#include <vector>
/*
	Class that governs all enemies
*/
class EnemyControler
{
public:

	EnemyControler();

	void moveEnemies();
	void drawEnemies(sf::RenderWindow& window);

	int getAliveEnemies();

	sf::Vector2f randomLowestEnemyPosition();
	sf::Vector2f lowestRightestEnemyPosition();

	std::vector<sf::Vector2f> bulletCollision(std::vector<Bullet>& bullets);

	ResourceManager enemyResourceManager;
private:
	const int gapBetweenEnemies = 10;

	int row = 5;
	int column = 11;
	int aliveEnemies = row * column;

	bool moveDown = false;
	bool moveLeft = false;

	float moveSpeed;

	sf::Sound invaderHit;
	sf::Clock moveTimer;
	sf::Time moveTimeGap;

	Animator enemyAnimator;

	std::vector<Enemy> enemies;
};