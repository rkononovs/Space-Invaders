#pragma once
#include <SFML/Graphics.hpp>

#include "EnemyControler.h"
#include "Player.h"
#include "Bullet.h"
/*
	This class manages all interactions between entity and world in game world including drawing and collision
*/
class GameManager
{
public:
	GameManager();
	void input();
	void getPlayerShootInput();
	void draw(sf::RenderWindow& window);
	void update();
private:
	void enemyShoot();
	void updateBullet();

	std::vector<sf::Vector2f> getCollisionPoints();

	bool isGameOver = false;

	Player player;
	EnemyControler enemy;

	sf::Clock enemyShotDelay;
	sf::Clock playerShotDelay;

	std::vector<Bullet> bullets;

};
