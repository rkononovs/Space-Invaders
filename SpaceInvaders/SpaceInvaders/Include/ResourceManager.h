#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class ResourceManager
{
public:
const sf::Texture* loadTexture(std::string fileName);

private:
	bool loadSuccess;
	sf::Texture textures;
	sf::SoundBuffer soundBuffers;
};
