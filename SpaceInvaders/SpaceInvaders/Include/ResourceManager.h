#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class ResourceManager
{
public:
sf::Texture& loadTexture(const std::string& fileName);
sf::Font& loadFont(const std::string& fileName);
//sf::SoundBuffer& loadSound(const std::string& fileName);

private:
	bool loadSuccess;
	sf::Texture textures;
	sf::SoundBuffer sounds;
	sf::Font fonts;
};
