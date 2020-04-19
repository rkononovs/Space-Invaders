#include "..\Include\ResourceManager.h"
#include <iostream>

sf::Texture& ResourceManager::loadTexture(const std::string& fileName)
{
	textures.loadFromFile(".\\Sprites\\" + fileName + ".png");
	return textures;
}

sf::Font& ResourceManager::loadFont(const std::string& fileName)
{
	fonts.loadFromFile(".\\Fonts\\" + fileName + ".ttf");
	return fonts;
}

/*sf::SoundBuffer& ResourceManager::loadSound(const std::string& fileName)
{
	//sounds.load
	//return sounds;
}*/