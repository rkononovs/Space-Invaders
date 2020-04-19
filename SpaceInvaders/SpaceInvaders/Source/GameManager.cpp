#include "../Include/GameManager.h"

GameManager::GameManager()
{
	invaderShot.setBuffer(gameResourceManager.loadSound("invaderBullet"));
	shipShot.setBuffer(gameResourceManager.loadSound("shipBullet"));
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
			auto bulletPosition = player.getSpritePosition();
			bulletPosition.y -= Bullet::bulletHeight; // Change y so bullet doesn't spawn inside player and kill him
			bulletPosition.x += player.playerWidth / 2; // Change x so bullet shoots from middle
			bullets.emplace_back(bulletPosition, Bullet::Direction::Up);
			shipShot.play();
			playerShotDelay.restart();
		}
}

void GameManager::enemyShoot()
{
	if (enemyShotDelay.getElapsedTime().asSeconds() > 0.25f && (rand() % 10 == 5)) { // randomize shooting interval
		sf::Vector2f point = enemy.randomLowestEnemyPosition();
		bullets.emplace_back(point, Bullet::Direction::Down);
		invaderShot.play();
		enemyShotDelay.restart();
	}
}

void GameManager::updateBullet()
{
	for (auto iterator = begin(bullets); iterator != end(bullets);) {
		auto& bullet = *iterator;
 		if (bullet.isBulletActive()) {
			if (bullet.isColliding(player)) { // If bullet collided with player clear screen of bulletss
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

std::vector<sf::Vector2f> GameManager::getCollisionPoints() // returns collision points, was intended to use for emplacing explosions to collision points
{
	auto collisionPoint = enemy.bulletCollision(bullets);
	auto blockadeCollision = blockade.bulletCollision(bullets);

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

bool GameManager::won()
{
	if (enemy.getAliveEnemies() == 0) {
		return true;
	}

	return false;
}

bool GameManager::isGameLost()
{
	if (player.getLives() == 0) {
		return true;
	}
	
	if (enemy.lowestRightestEnemyPosition().y >= player.getSpritePosition().y) {
		return true;
	}

	return false;
}