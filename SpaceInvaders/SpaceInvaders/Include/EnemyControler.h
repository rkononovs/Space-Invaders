#pragma once

#include "Enemy.h"

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

	std::vector<Enemy> enemies;
};
