#pragma once
#include <SFML/Graphics.hpp>

#include "../Include/Collidable.h"
#include "../Include/ScreenInfo.h"
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

	bool isAlive();

	const sf::Vector2f& getSpritePosition();

	constexpr static float playerWidth = 30.0f;
	constexpr static float playerHeight = 30.0f;
private:
	sf::RectangleShape player;
	sf::Vector2f playerVelocity;

	float baseHeight = (float)Screen::height - 40.0f; // Set player position base heigth to 40


	bool isPlayerAlive = true;
	int speed = 1;
};
