#include "../Include/GameManager.h"
#include <iostream> // DEBUGING PURPOSES ! DELETE LATER !

GameManager::GameManager()
{

}

void GameManager::input()
{
	if (player.isAlive()) {
		player.getMoveInput();
		getPlayerShootInput();
	}
	else {
		player.revivePlayer();
	}
}

void GameManager::getPlayerShootInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && playerShotDelay.getElapsedTime().asSeconds() > 1.0f) {
			std::cout << "SHOOT" << std::endl; // DEBUGING PURPOSES ! DELETE LATER 
			auto bulletPosition = player.getSpritePosition();
			bulletPosition.y -= 10; // Change y so bullet doesn't spawn inside player and kill him
			bullets.emplace_back(bulletPosition, Bullet::Direction::Up);
			std::cout << playerShotDelay.getElapsedTime().asSeconds() << std::endl;
			playerShotDelay.restart();
		}
}

void GameManager::enemyShoot()
{
	if (enemyShotDelay.getElapsedTime().asSeconds() > 0.25f && (rand() % 10 == 5)) {
		sf::Vector2f point = enemy.randomLowestEnemyPosition();
		bullets.emplace_back(point, Bullet::Direction::Down);
		enemyShotDelay.restart();
	}
}

void GameManager::updateBullet()
{
	for (auto iterator = begin(bullets); iterator != end(bullets);) {
		auto& bullet = *iterator;
 		if (bullet.isBulletActive()) {
			if (bullet.isColliding(player)) {
				bullets.clear();
				return;
			}
			bullet.updateBullet();
			iterator++;
		}
		else {
			iterator = bullets.erase(iterator);
		}
	}
}

std::vector<sf::Vector2f> GameManager::getCollisionPoints()
{
	auto collisionPoint = enemy.bulletCollision(bullets);
	auto blockadeCollision = blockade.bulletCollision(bullets);
//	if (enemy.checkBulletCollisions(bullets)) {
		//enemy.destroyEnemy();
		//playerShotDelay.restart();
//	}
	updateBullet();
	
	return collisionPoint;
}



void GameManager::draw(sf::RenderWindow& window)
{
	for (auto& Bullet : bullets) {
		if (Bullet.isBulletActive()) {
			Bullet.drawBullet(window);
		}
	}
	if (player.isAlive()) {
		player.drawPlayer(window);
	}
	enemy.drawEnemies(window);
	blockade.drawBlockades(window);
}

void GameManager::update()
{
	enemyShoot();
	getCollisionPoints();

	player.updatePlayer();
	enemy.moveEnemies();
}
