#include "../Include/GameManager.h"
#include <iostream> // DEBUGING PURPOSES ! DELETE LATER !

GameManager::GameManager()
{

}

void GameManager::input()
{
	player.getMoveInput();
	getPlayerShootInput();
}

void GameManager::getPlayerShootInput()
{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			std::cout << "SHOOT" << std::endl; // DEBUGING PURPOSES ! DELETE LATER 
			auto playerPosition = player.getSpritePosition();
			bullets.emplace_back(playerPosition, Bullet::Direction::Up);
		}
}

void GameManager::enemyShoot()
{
}

void GameManager::updateBullet(std::vector<sf::Vector2f>& collisionPoint)
{
	for (auto iterator = bullets.begin(); iterator != bullets.end();) {
		auto& bullet = *iterator;
		if (!bullet.isBulletActive()) {
			iterator = bullets.erase(iterator);
		}
	}
}

std::vector<sf::Vector2f> GameManager::getCollisionPoints()
{
	auto collisionPoint = enemy.bulletCollision(bullets);
	updateBullet(collisionPoint);
	
	return collisionPoint;
}



void GameManager::draw(sf::RenderWindow& window)
{
	for (auto& Bullet : bullets) {
		if (Bullet.isBulletActive()) {
			Bullet.updateBullet();
			Bullet.drawBullet(window);
		}
	}
	player.drawPlayer(window);
	enemy.drawEnemies(window);
}

void GameManager::update()
{
	auto collisions = enemy.bulletCollision(bullets);

	player.updatePlayer();
	enemy.moveEnemies();
}
