#include "../Include/EnemyControler.h"

EnemyControler::EnemyControler()
{
	Enemy::Type types[] = {
		Enemy::Type::Squid, Enemy::Type::Crab, Enemy::Type::Crab,
		Enemy::Type::Octopus, Enemy::Type::Octopus
	};


	const int gapBetweenEnemies = 10;
	for (int y = 0; y < 5; y++) { // Add enemies to the vector
		for (int x = 0; x < 11; x++){
			float enemyX = x * 40 + (gapBetweenEnemies * x * 3) + 40; // TODO Change 40 to invader width
			float enemyY = y * 40 + (gapBetweenEnemies * y) + 40; // TODO Change 40 to invader height
			enemies.emplace_back(sf::Vector2f{ enemyX, enemyY }, types[y]);
		}
	}
}

void EnemyControler::moveEnemies()
{
}

void EnemyControler::drawEnemies(sf::RenderWindow& window)
{
	for (auto& Enemy : enemies) {
		Enemy.drawEnemy(window);
	}
}
