// Player class, that will have specific methods and attributes for player
#pragma once
class Player
{
public:
	Player();
	void drawPlayer(sf::RenderWindow &window);
	void getInput();
	void updatePlayer();
private:
	sf::RectangleShape player;
	sf::Vector2f playerVelocity;

	bool isAlive = true;
	int speed = 1;
};
