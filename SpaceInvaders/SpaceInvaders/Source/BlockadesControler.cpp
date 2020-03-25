#include "..\Include\BlockadesControler.h"

#include <iostream>

BlockadesControler::BlockadesControler()
{
	for (int x = 0; x < blockadesAmount; x++) {
		float blockadesX = x * 50 + (gapBetweenBlockades * x * 3) + Blockade::blockadesWidth;
		blockades.emplace_back(sf::Vector2f{ blockadesX, baseBlockadesHeight });
	}
}

void BlockadesControler::drawBlockades(sf::RenderWindow& window)
{
	for (auto& blockade : blockades) {
		blockade.drawBlockade(window);
	}
}

void BlockadesControler::destroyBlockades()
{
}

std::vector<sf::Vector2f> BlockadesControler::bulletCollision(std::vector<Bullet>& bullets)
{
	std::vector<sf::Vector2f> attackedBlockadePosition;
	for (auto& bullet : bullets) {
		for (auto& blockade : blockades) {
			if (blockade.isActive()) {
				if (bullet.isColliding(blockade)) {
				}
			}
		}
	}

	return attackedBlockadePosition;
}
