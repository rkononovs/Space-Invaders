#include "..\Include\ResourceManager.h"
#include <iostream>

sf::Texture& ResourceManager::loadTexture(const std::string& fileName)
{
	textures.loadFromFile(".\\Sprites\\" + fileName + ".png");
	return textures;
}
//enemyResourceManager.loadTexture("enemySheet")