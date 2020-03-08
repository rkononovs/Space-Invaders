#pragma once

#include "Enemy.h"
#include "ScreenInfo.h"

#include <vector>

class EnemyControler
{
public:

	EnemyControler();

	void moveEnemies();
	void drawEnemies(sf::RenderWindow& window);

private:
	int row = 5; // Later possible should be deleted
	int column = 11; // Both...

	bool moveDown = false;
	bool moveLeft = false;

	float moveSpeed;

	sf::Clock moveTimer;
	sf::Time moveGap;
	std::vector<Enemy> enemies;
};
