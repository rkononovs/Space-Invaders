#include "../Include/EnemyControler.h"
#include <stdlib.h> // For rand() function
#include <iostream> // DEBUGING PURPOSES ! DELETE LATER !

EnemyControler::EnemyControler() : moveTimeGap(sf::seconds(0.75f))
{
	Enemy::Type types[] = {
		Enemy::Type::Squid, Enemy::Type::Crab, Enemy::Type::Crab,
		Enemy::Type::Octopus, Enemy::Type::Octopus
	};


	for (int y = 0; y < row; y++) { // Add enemies to the vector
		for (int x = 0; x < column; x++){
			float enemyX = x * 40 + (gapBetweenEnemies * x * 3) + Enemy::enemyWidth; // TODO Change 40 to invader width
			float enemyY = y * 40 + (gapBetweenEnemies * y) + Enemy::enemyHeight; // TODO Change 40 to invader height
			enemies.emplace_back(sf::Vector2f{ enemyX, enemyY }, types[y]);
		}
	}
}

void EnemyControler::moveEnemies()
{
	if (moveTimer.getElapsedTime() > moveTimeGap) {
		steps++; // DEBUGING PURPOSES ! DELETE LATER !
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
		for (auto& enemy : enemies) {
			enemy.moveEnemy(moveSpeed, 0.0f);
			if (moveDown) {
				enemy.moveEnemy(0.0f, 20.0f); // TODO Later change 20 to variable 
			}
			else if (!isMovingDown) {
				isMovingDown = ((enemy.getSpritePosition().x < 10 && moveLeft) 
					|| (enemy.getSpritePosition().x + Enemy::enemyWidth > Screen::width - 10 && !moveLeft));
			}
		}
		if (moveDown) {
			moveLeft = !moveLeft;
		}
		std::cout << "Horizontal steps: " << steps << std::endl; // DEBUGING PURPOSES ! DELETE LATER !
		moveDown = isMovingDown;
		moveTimer.restart();
	}
}

void EnemyControler::drawEnemies(sf::RenderWindow& window)
{
	for (auto& enemy : enemies) {
		enemy.drawEnemy(window);
	}
}

/*void EnemyControler::destroyEnemy()                   /// For now I don't need this function, but I may use it later. ///
{
	for (auto iterator = begin(enemies); iterator != end(enemies);) {
		auto& enemy = *iterator;
		if (enemy.isAlive()) {
			iterator++;
		}
		else {
			std::cout << "Enemy Destroyed" << std::endl;
			iterator = enemies.erase(iterator);
		}
	}
}*/ 

bool EnemyControler::checkBulletCollisions(std::vector<Bullet>& bullets) {
	for (auto& bullet : bullets) {
		for (auto& enemy : enemies) {
			if (enemy.isAlive()) {
				if (bullet.isColliding(enemy)) {
					return true;
				}
				else {
					return false;
				}
			}
			else {
				false;
			}
		}
	}
}

sf::Vector2f EnemyControler::randomLowestEnemyPosition()
{
	while (true) {
		int enemyRandColumn = rand() % column;
		for (int y = row - 1; y >= 0; y--) {
			int index = y * column + enemyRandColumn;
			auto& enemy = enemies.at(index);
			if (enemy.isAlive()) {
				return
				{
					enemy.getSpritePosition().x + enemy.enemyWidth / 2,
					enemy.getSpritePosition().y + enemy.enemyHeight + 5
				};
			}
		}
	}
}

/* for (auto iterator = begin(bullets); iterator != end(bullets);) {
	auto& bullet = *iterator;
	if (bullet.isBulletActive()) {
		bullet.updateBullet();
		iterator++;
	}
	else {
		iterator = bullets.erase(iterator);
	}
}  */

std::vector<sf::Vector2f> EnemyControler::bulletCollision(std::vector<Bullet>& bullets)
{
	std::vector<sf::Vector2f> killedEnemyPosition;
	for (auto& bullet : bullets) {
		for (auto& enemy : enemies) {
			if (enemy.isAlive()) {
				if (bullet.isColliding(enemy)) {
					aliveEnemies--;
					killedEnemyPosition.emplace_back(enemy.getSpritePosition());
				}
			}
		}
	}

	return killedEnemyPosition;
}

// Fix collision box