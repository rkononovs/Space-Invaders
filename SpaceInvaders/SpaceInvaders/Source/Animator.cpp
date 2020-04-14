#include <iostream>
#include "../Include/Animator.h"

Animator::Animator(float width, float height, const sf::Texture& sprite)
{
	enemyObj.setSize({ width, height });
	enemyObj.setTexture(&sprite);
}

void Animator::nextFrame()
{
	currentFrame++;
}

void Animator::renderEnemy(sf::RenderTarget& target, int type, const sf::Vector2f& position)
{
	int texCordTop = (type * frameHeight);
	int texCordLeft = frameWidth * (currentFrame % 2);
	enemyObj.setPosition(position);
	enemyObj.setTextureRect({texCordLeft, texCordTop, frameWidth, frameHeight });
	target.draw(enemyObj);
}
