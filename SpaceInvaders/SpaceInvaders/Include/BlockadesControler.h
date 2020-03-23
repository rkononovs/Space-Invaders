#pragma once
#include "../Include/Blockade.h"
#include "../Include/Bullet.h"
#include "../Include/ScreenInfo.h"

#include <vector>

class BlockadesControler
{
public:
	BlockadesControler();
	void drawBlockades(sf::RenderWindow& window);
	void destroyBlockades();
	
	std::vector<sf::Vector2f> bulletCollision(std::vector<Bullet>& bullets);

private:
	float baseBlockadesHeight = (float)Screen::height - 200.0f; // Set blockades position base heigth to 120
	int gapBetweenBlockades = 70;
	int blockadesAmount = 4;

	std::vector<Blockade> blockades;
};
