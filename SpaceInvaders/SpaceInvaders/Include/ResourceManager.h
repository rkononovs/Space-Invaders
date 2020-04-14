#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class ResourceManager
{
public:
sf::Texture& loadTexture(const std::string& fileName);

private:
	bool loadSuccess;
	sf::Texture textures;
	sf::SoundBuffer soundBuffers;
};
