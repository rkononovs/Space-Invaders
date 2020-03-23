#include "../Include/Blockade.h"


Blockade::Blockade(sf::Vector2f startingPosition) : Collidable(blockadesWidth, blockadesHeight), newPosition(startingPosition)
{

}

void Blockade::onCollision(Collidable& other)
{
}

void Blockade::drawBlockade(sf::RenderWindow& window)
{
	sf::RectangleShape blockade;
	blockade.setSize(sf::Vector2f(blockadesWidth, blockadesHeight));
	blockade.setPosition(newPosition);
	blockade.setFillColor(sf::Color::Red);

		window.draw(blockade);
	
}

const sf::Vector2f& Blockade::getSpritePosition()
{
	return newPosition;
}
