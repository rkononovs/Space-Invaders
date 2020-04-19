#pragma once
#include <SFML/Graphics.hpp>

#include "../Include/Collidable.h"
#include "../Include/ScreenInfo.h"
#include "../Include/ResourceManager.h"
/*
	Class for the player
*/

class Player : public Collidable
{
public:
	Player();
	void drawPlayer(sf::RenderWindow &window);
	void getMoveInput();
	void updatePlayer();
	void onCollision(Collidable& object);
	void revivePlayer();
	int getLives();

	bool isAlive();

	const sf::Vector2f& getSpritePosition();

	constexpr static float playerWidth = 30.0f; // TODO: CHANGE TO RIGHT VALUE
	constexpr static float playerHeight = 30.0f; // SAME
private:
	int speed = 1;
	int lives = 3;

	bool isPlayerAlive = true;

	float baseHeight = (float)Screen::height - 40.0f; // Set player position base heigth to 40
	sf::RectangleShape player;
	sf::Vector2f playerVelocity;
	ResourceManager playerResourceManager;
};
