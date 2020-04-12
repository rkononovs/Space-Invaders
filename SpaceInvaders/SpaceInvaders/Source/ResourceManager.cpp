
#include "..\Include\ResourceManager.h"

const sf::Texture* ResourceManager::loadTexture(std::string fileName)
{
	textures.loadFromFile(".\\Sprites\\" + fileName + ".png");

	return& textures;
}
