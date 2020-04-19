#include "../Include/EnemyControler.h"
#include <stdlib.h> // For rand() function

EnemyControler::EnemyControler() : moveTimeGap(sf::seconds(0.75f))
, enemyAnimator(Enemy::enemyWidth, Enemy::enemyHeight, enemyResourceManager.loadTexture("enemySheet"))
{
	Enemy::Type types[] = {
		Enemy::Type::Squid, Enemy::Type::Crab, Enemy::Type::Crab,
		Enemy::Type::Octopus, Enemy::Type::Octopus
	};

	for (int y = 0; y < row; y++) { // Add enemies to the vector
		for (int x = 0; x < column; x++){
			float enemyX = x * 40 + (gapBetweenEnemies * x * 3) + Enemy::enemyWidth; // Make gap between them on X axis
			float enemyY = y * 40 + (gapBetweenEnemies * y) + Enemy::enemyHeight; // Make gap between them on Y axis
			enemies.emplace_back(sf::Vector2f{ enemyX, enemyY }, types[y]);
		}
	}

	invaderHit.setBuffer(enemyResourceManager.loadSound("invaderHit"));
}

void EnemyControler::moveEnemies()
{
	if (moveTimer.getElapsedTime() > moveTimeGap) { // Move enemies each 0.75 seconds / See line 5 /
		enemyAnimator.nextFrame();
		bool isMovingDown = false;
		if (moveLeft) {
			moveSpeed = -20.0f;
		}
		else if(!moveLeft)
		{
			moveSpeed = 20.0f;
		}

		if (moveDown) {
			moveSpeed *= -1;
		}

		// Move every enemy
		for (auto& enemy : enemies) {
			enemy.moveEnemy(moveSpeed, 0.0f);
			if (moveDown) {
				enemy.moveEnemy(0.0f, 20.0f);
			}
			else if (!isMovingDown) { // Check if is near screen
				isMovingDown = ((enemy.getSpritePosition().x < 10 && moveLeft) 
					|| (enemy.getSpritePosition().x + Enemy::enemyWidth > Screen::width - 10 && !moveLeft));
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
	for (auto& enemy : enemies) {
		if (enemy.isAlive()) {
			enemyAnimator.renderEnemy(window, (int)enemy.getType(), enemy.getSpritePosition());
		}
	}
}

int EnemyControler::getAliveEnemies()
{
	return aliveEnemies;
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

sf::Vector2f EnemyControler::lowestRightestEnemyPosition()
{
	while (true) {
		for (int y = row - 1; y >= 0; y--) {
			for(int x = column -1; x >=0; x--){
				int index = y * column + x;
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
}

std::vector<sf::Vector2f> EnemyControler::bulletCollision(std::vector<Bullet>& bullets)
{
	std::vector<sf::Vector2f> killedEnemyPosition;
	for (auto& bullet : bullets) {
		for (auto& enemy : enemies) {
			if (enemy.isAlive()) {
				if (bullet.isColliding(enemy)) {
					aliveEnemies--;
					invaderHit.play();
					killedEnemyPosition.emplace_back(enemy.getSpritePosition());
				}
			}
		}
	}

	return killedEnemyPosition;
}