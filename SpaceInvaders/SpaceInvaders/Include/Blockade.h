#pragma once
#include <SFML/Graphics.hpp>

#include "../Include/Collidable.h"
#include "../Include/ScreenInfo.h"
class Blockade : public Collidable
{
public:
	enum class Stages {
		Destroyed, Partial, Complete
	};
	Blockade(sf::Vector2f startingPosition);
	void onCollision(Collidable& object);
	void drawBlockade(sf::RenderWindow& window);

	const sf::Vector2f& getSpritePosition();

	constexpr static float blockadesWidth = 75.0f;
	constexpr static float blockadesHeight = 75.0f;
private:
	int healthLeft = 2;

	sf::Vector2f newPosition;

	Stages damageStages;

};