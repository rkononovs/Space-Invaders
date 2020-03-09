#include "../Include/EnemyControler.h"
#include <iostream> // DEBUGING PURPOSES ! DELETE LATER !

EnemyControler::EnemyControler() : moveGap(sf::seconds(0.05f))
{
	Enemy::Type types[] = {
		Enemy::Type::Squid, Enemy::Type::Crab, Enemy::Type::Crab,
		Enemy::Type::Octopus, Enemy::Type::Octopus
	};


	const int gapBetweenEnemies = 10;
	for (int y = 0; y < 5; y++) { // Add enemies to the vector
		for (int x = 0; x < 11; x++){
			float enemyX = x * 40 + (gapBetweenEnemies * x * 3) + Enemy::enemyWidth; // TODO Change 40 to invader width
			float enemyY = y * 40 + (gapBetweenEnemies * y) + Enemy::enemyHeight; // TODO Change 40 to invader height
			enemies.emplace_back(sf::Vector2f{ enemyX, enemyY }, types[y]);
		}
	}
}

void EnemyControler::moveEnemies()
{
	if (moveTimer.getElapsedTime() > moveGap) {
		bool isMovingDown = false;
		if (moveLeft) {
			moveSpeed = -10.0f;
		}
		else if(!moveLeft)
		{
			moveSpeed = 10.0f;
		}

		if (moveDown) {
			moveSpeed *= -1;
		}

		// Move every enemy
		for (auto& Enemy : enemies) {
			Enemy.moveEnemy(moveSpeed, 0.0f);
			if (moveDown) {
				Enemy.moveEnemy(0.0f, 20.0f); // TODO Later change 20 to variable 
				std::cout << Enemy.getPosition().y << std::endl; // DEBUGING PURPOSES ! DELETE LATER !
			}
			else if (!isMovingDown) {
				isMovingDown = ((Enemy.getPosition().x < 10 && moveLeft) 
					|| (Enemy.getPosition().x + Enemy::enemyWidth > Screen::width - 10 && !moveLeft));
				std::cout << "It is: " << isMovingDown << std::endl;
			}
		}
		if (moveDown) {
			moveLeft = !moveLeft;
		}
		moveDown = isMovingDown;
		moveTimer.restart();
	}
}

void EnemyControler::drawEnemies(sf::RenderWindow& window)
{
	for (auto& Enemy : enemies) {
		Enemy.drawEnemy(window);
	}
}
