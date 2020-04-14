#pragma once
#include <SFML/Graphics.hpp>

class Animator
{
public:
	Animator(float width, float height, const sf::Texture& sprite);
	void nextFrame();
	void renderEnemy(sf::RenderTarget& target, int type, const sf::Vector2f& position);
private:
	sf::RectangleShape enemyObj;
	int currentFrame = 0;
	int frameWidth = 32;
	int frameHeight = 32;
};
