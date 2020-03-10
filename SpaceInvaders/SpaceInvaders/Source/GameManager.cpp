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
			auto playerPosition = player.getPlayerPosition();
			bullets.emplace_back(playerPosition, Bullet::Direction::Up);
		}
}

void GameManager::enemyShoot()
{
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
	player.updatePlayer();
	enemy.moveEnemies();
}
