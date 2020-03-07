#include <SFML/Graphics.hpp>
#include "Include/ScreenInfo.h"
#include "Include/Player.h"

int main()
{

	sf::RenderWindow window(sf::VideoMode(Screen::width, Screen::height), "Space Invaders");
	sf::Event event;
	Player playerOne;

	window.setFramerateLimit(60);

	while (window.isOpen()) 
	{
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}
		window.clear(sf::Color::White);

		playerOne.drawPlayer(window);
		playerOne.getInput();
		playerOne.updatePlayer();

		window.display();
	}
}