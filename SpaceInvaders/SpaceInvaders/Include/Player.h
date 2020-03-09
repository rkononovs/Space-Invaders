#pragma once
#include <SFML/Graphics.hpp>

#include "../Include/ScreenInfo.h"
class Player
{
public:
	Player();
	void drawPlayer(sf::RenderWindow &window);
	void getMoveInput();
	void updatePlayer();
	const sf::Vector2f& getPlayerPosition();
private:
	sf::RectangleShape player;
	sf::Vector2f playerVelocity;

	bool isPlayerAlive = true;
	int speed = 1;
};
