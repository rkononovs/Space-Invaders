#include "../Include/Blockade.h"

Blockade::Blockade(sf::Vector2f startingPosition) : Collidable(blockadesWidth, blockadesHeight), newPosition(startingPosition)
{
	blockade.setSize(sf::Vector2f(blockadesWidth, blockadesHeight));
	blockade.setPosition(newPosition);
	blockade.setFillColor(sf::Color::Green);
}

void Blockade::onCollision(Collidable& other)
{
	healthLeft--;

	if (healthLeft <= 0) {
		isBlockadeActive = false;
	}
	else if (healthLeft == 1) {
		blockade.setFillColor(sf::Color::White);
	}

}

void Blockade::drawBlockade(sf::RenderWindow& window)
{
	if (isBlockadeActive) {
		window.draw(blockade);
	}
}

bool Blockade::isActive()
{
	return isBlockadeActive;
}

const sf::Vector2f& Blockade::getSpritePosition()
{
	return newPosition;
}
