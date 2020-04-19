#pragma once
#include <SFML/Graphics.hpp>

#include "../Include/ResourceManager.h"
#include "../Include/BlockadesControler.h"
#include "../Include/EnemyControler.h"
#include "../Include/Player.h"
#include "../Include/Bullet.h"
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

	bool won();
	bool isGameLost();

private:
	void enemyShoot();
	void updateBullet();

	std::vector<sf::Vector2f> getCollisionPoints();

	bool isGameOver = false;

	Player player;
	EnemyControler enemy;
	BlockadesControler blockade;
	ResourceManager gameResourceManager;

	sf::Sound invaderShot;
	sf::Sound shipShot;

	sf::Clock enemyShotDelay;
	sf::Clock playerShotDelay;

	std::vector<Bullet> bullets;

};
